#include <glib.h>
#include <stdio.h>
#include "debug.h"
#include "itemaccess.h"
#include "osm_protobuf.h"

int main (int argc, char** argv) {

   debug_init(argv[0]);
   debug_level_set(DEBUG_MODULE_GLOBAL, lvl_debug);

   map_collect_data_osm_protobuf(stdin);
   return 0;
}
