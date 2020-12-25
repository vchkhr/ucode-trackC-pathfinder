#include "../inc/pathfinder.h"

t_path *create_path(int island, int distance) {
	t_path *path = (t_path *)malloc(sizeof(t_path));

	path->pathID = island;
	path->pathDistance = distance;
	path->nextConnect = NULL;
	path->nextPath = NULL;
	
	return path;
}
