#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

typedef struct s_path {
    int pathID;
    int pathDistance;
    int index;
    struct s_path *nextConnect;
    struct s_path *nextPath;
}		       t_path;

typedef struct s_island {
    int islandID;
    int destination;
    struct s_path *path;
    struct s_island *next;
}		       t_island;

typedef struct s_output {
    char *path;
    char *route;
    char *distance;
    int distance_int;
}		       t_output;

typedef struct s_size_int {
    int size;
    int root;
}		       t_size_int;

typedef struct s_matrix {
    int island1;
    int island2;
    int matrix;
}		       t_matrix;

typedef struct s_path_list{
    t_island *unvisited;
    t_island *visited;
    t_island *current;
    t_island *shortest;
}		       t_path_list;

int **create_matrix(char **set, char ***arrarr);
int add_index_pathes(t_path **path);
int compare_fast(t_path *bond, t_path *fastest);
int count_set(char **array, char *new_islands);
int create_flag(char *array_x2, char **set_array);
int get_unique_path(t_path **new, t_path **pre);
t_island *create_island(int isl, int dist);
t_island *shortest_distance(t_island **unvisited);
t_output *create_result_line(t_path *bond, char **set);
t_path *add_one_path(t_path **previous, int isl, int dist);
t_path *add_path(t_path **previous, int isl, int dist);
t_path *add_previous_path(t_path **previous);
t_path *copy_path(t_path **data);
t_path *create_path(int isl, int dist);
t_path_list *create_path_list();
void add_link(t_path **current, t_path **new);
void add_link(t_path **current, t_path **new);
void add_next_bond(t_output **prd, t_path *bond, char *destination, char **set);
void algorithm(int **matrix, char **set, t_size_int *in);
void check_lines(char **lines, int line_number);
void check_spaces(char **src, char *file);
void compare_pathes(t_path **new, t_path **current, int *flag);
void create_array(char **src, char ***arrarr);
void create_set(char ***set, char ***arrarr, char *numOfIsland);
void delete_matrix(int ***matrix, char **set);
void delete_path(t_path **head);
void error_duplicate_bridges();
void error_file_empty(char *file_name);
void error_file_not_exist(char *file_name);
void error_invalid_arguments();
void error_invalid_number_of_islands();
void error_line_1_is_not_valid();
void error_line_is_not_valid(int number_of_line);
void error_sum_of_bridges_lengths_is_too_big();
void fill_islands(char ***arr_x3, char **lines, int line);
void fill_matrix(char **set, char **array, int ***matrix, t_size_int *size_int);
void get_line_from_array(char *line, char **island1, char **island2, char **distance);
void island_pop_front(t_island **head);
void island_pop_middle(t_island **unvisited, int index);
void join(char **res, char *s2);
void length(t_path_list **path_list, int **matrix, char **set);
void median(t_island **unvisited, t_island **current, int **mat, t_matrix **matrix);
void parse_file(char *fd, int ***matrix, char ***set);
void path_push_back(t_path **path, t_path **previous, int isl, int dist);
void pathfinder(int **matrix, char **set);
void pbi(t_island **island, t_path **path, int isl, int dist);
void pop_all_bonds(t_path **head);
void pop_next_path(t_path **head);
void print_delimiter();
void print_invalid(int line_number);
void print_path(t_path **disp, int destination, char **set);
void print_result(t_island **visited, int root, int size, char **set);
void print_result_line(t_output **prd);
void process_matrix(char **set, char **arrarr, int ***matrix);
void process_next_step(t_path **old, t_path **path, t_path **new);
void process_path(t_island **unvisited, t_island **current, t_island **visited, t_size_int *size_int);
void sort_pathes(t_path **disp, int sizeP);
void swap(t_path **distance, t_path **bond, t_path **fastest);
void swap_distance(t_path **distance, t_path **bond, t_path **fastest);
void test_for_errors(int argc, char *file, char **argv);

#endif
