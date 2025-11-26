

/**
     * \defgroup Core
     *  \dot
     *  digraph DependencyGraph {
     *      
     *      Memory [ label="Memory"];
     *      DS [ label="DS"]
     *      IO [ label = "IO" ]
     *      Stream [label = "Stream"]
     *      Log [Label = "Log"]
     *      File [ label = "File" ]
     *      
     *      Memory -> DS;
     *      Stream -> Memory;
     *      File -> Stream;
     *      Log -> Stream; 
     *  }
     *  \enddot
     */