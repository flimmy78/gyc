#include "dictionary.h"
#include "graph_attack.h"
#include "graph_components.h"
#include "graph_topological_properties.h"
#include "graph_centrality.h"
#include "graph_fastcommunity.h"
#include "graph_community.h"
#include "lex.h"
#include "parser.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>

/* --degree_centrality the degree of each vertex. */
char *deg_cen_file_name = NULL;
/* --degree_distribution the degree distribution. */
char *deg_dis_file_name = NULL;
/* --in_out_relation */
char *in_out_file_name = NULL;
/* --clustering_coefficient_centrality */
char *cc_cen_file_name = NULL;
/* --fast_community */
char *fc_file_name = NULL;
/* --fast_community_edges */
char *fc_edge_file_name = NULL;
/* --fast_community_vertices */
char *fc_vertex_file_name = NULL;
/* --fast_community_com_file */
char *fc_com_file_name = NULL;
/* --robustness */
char *att_info_file_name = NULL;

unsigned int out_flag = 0x0000;
/* --ct format output for network. */
#define CT_FLAG 0x0001
/* --dot format output for graphviz. */
#define DOT_FLAG 0x0002
/* --in the input file or directory. */
char *inPath = NULL;
/* --out the output file. */
char *outFileName = NULL;
/* --extension	the file's extension. */
char *extension = NULL;

void usage(int i)
{
    fprintf(stderr, "Usage:  gyc.exe (directory|file) [options]\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "===================================\n");
	fprintf(stderr, "\t--out\t\tthe output file.\n");
	fprintf(stderr, "\t--extension\tthe file's extension.\n");
	fprintf(stderr, "\t--ct\t\tformat output for network.\n");
	fprintf(stderr, "\t--dot\t\tformat output for graphviz.\n");
    fprintf(stderr, "\t--help\t\tdisplay this help and exit.\n");
    fprintf(stderr, "===================================\n");
	fprintf(stderr, "\t--degree_centrality\n");
	fprintf(stderr, "\t\tthe degree of each vertex.\n");
	fprintf(stderr, "\t--degree_distribution\n");
	fprintf(stderr, "\t\tthe degree distribution.\n");
	fprintf(stderr, "\t--in_out_relation\n");
	fprintf(stderr, "\t\tthe relationship between indegrees and outdegrees.\n");
	fprintf(stderr, "\t--clustering_coefficient_centrality\n");
	fprintf(stderr, "\t\tthe clustering coefficient of each vertex.\n");
    fprintf(stderr, "===================================\n");
	fprintf(stderr, "\t--fast_community\n");
	fprintf(stderr, "\t\tmapping each vertex into a community.\n");
	fprintf(stderr, "\t--fast_community_edges\n");
	fprintf(stderr, "\t\tthe edges among communities.\n");
	fprintf(stderr, "\t--fast_community_vertices\n");
	fprintf(stderr, "\t\tthe information of communities.\n");
	fprintf(stderr, "\t--fast_community_com_file.\n");
	fprintf(stderr, "\t\tcommunity files.\n");
    fprintf(stderr, "===================================\n");
	fprintf(stderr, "\t--robustness.\n");
	fprintf(stderr, "\t[I,G]:[random,in,out][p=0.2,f=0.1]length=0.1\t\n");
    fprintf(stderr, "end.\n");
    exit(i);
}


void setup_option(int argc, char* argv[])
{
    if (0 != argc) {
        char *tmp = argv[0];
        int len = strlen(tmp);
        int p = 1;

		if (0 == strcmp("--help", tmp))
			usage(0);
		else if (0 == strcmp("--ct", tmp))
			out_flag = CT_FLAG;
		else if (0 == strcmp("--dot", tmp))
			out_flag = DOT_FLAG;
		else if (0 == strcmp("--degree_centrality", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			deg_cen_file_name = argv[0];
		} else if (0 == strcmp("--degree_distribution", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			deg_dis_file_name = argv[0];
		} else if (0 == strcmp("--in_out_relation", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			in_out_file_name = argv[0];
		} else if (0 == strcmp("--clustering_coefficient_centrality", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			cc_cen_file_name = argv[0];
		} else if (0 == strcmp("--extension", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			else if (0 != strcmp(".ct", argv[0]) && 0 != strcmp(".c", argv[0]))
				usage(1);
			extension = argv[0];
		} else if (0 == strcmp("--out", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			outFileName = argv[0];
		} else if (0 == strcmp("--fast_community", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			fc_file_name = argv[0];
		} else if (0 == strcmp("--fast_community_edges", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			fc_edge_file_name = argv[0];
		} else if (0 == strcmp("--fast_community_vertices", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			fc_vertex_file_name = argv[0];
		} else if (0 == strcmp("--fast_community_com_file", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			fc_com_file_name = argv[0];
		} else if (0 == strcmp("--robustness", tmp)) {
			argc--; argv++;
			if (argc == 0)
				usage(1);
			att_info_file_name = argv[0];
		} else
			usage(1);

		argc--; argv++;
        setup_option(argc, argv);
    }
}

void network_fast_community(graph_t *lkn)
{
	int ncom = 0;
	vector_int v1;
	vector_int_init(&v1,0);
	vector_char str;
	vector_char_init(&str, 100);


	double modularity = graph_community_fastgreedy(lkn, &v1, &ncom);
	ncom = vector_int_max(&v1) + 1;
	printf("modularity:\t%f\nncom:\t%d\n", modularity, ncom);

	print_vector_int3(&v1, '\t', stdout);
	output_community_graph(lkn, &v1, stdout, stdout);


	vector_int_destroy(&v1);
}

int main(int argc, char* argv[])
{
	setup_option(argc-2, argv+2);

	SetupLexer();
	dic_setup();

	int n, m;
	vector_int edges;
	vector_int_init(&edges, 0);
	parse_adj_matrix_file(argv[1], &edges, &n, &m);
	printf("n=%d,m=%d\n",n,m);

    graph_t lkn;
    new_graph(&lkn, &edges, 0, GRAPH_DIRECTED);

	network_fast_community(&lkn);

	graph_destroy(&lkn);
	vector_int_destroy(&edges);

	return 0;
}
