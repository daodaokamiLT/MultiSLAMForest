## Multi SLAM Forest

1. node means different device: cam, imu, odom, lider.
2. tree means a set off the a slam hardsystem.
3. forest means serices of slam hardsystem in one env.

#### function

1. each node, each tree, each forest has themselves weight.
2. each node, each tree, each forest link each others.
3. each node, each tree, each forest can easily isolate with others.
4. each node, each tree, each forest can easily use common datas. -- as disruptor
5. each node, each tree, each forest can easily add and delete. 


#### data save structure

1. the best is the linkarray, all data save as a array, but data struct is different, but we can save the shared_ptr for each data. as a value, than make a indexstructure. the indexstructure manager all node, all tree, all forest.
2. how the node edge save ?   用邻接表的结构存储，边对应的结构。 adjacency list
3. how the tree edge save ?   用邻接表的结构存储，边对应的结构。
4. how the forest edge save ? 用邻接表的结构存储，边对应的结构。
5. how split some node in tree, and their edges?            device type， split cams， split imus， split odoms ... , given selectedarray
6. how split some trees in forest, and their edegs?         trees split by given selectedarray. splitted by features, like lost, hidden
7. how split some forest in AllGraphy, and their edges?     forset split by given selectdarray. splitted by features, like lost, hidden


#### info connection
<!-- can support 1000 humans in one service is great success! -->
1. local wifi or global wifi, by router or switcher 需要自动链接不同的wifi，并且可能交换机之间进行大量的数据传输也是可能的。
2. unlocked queue, like disruptor. can it be used by multi producer and mulit reader.



#### some idea

1. the local map is great important
2. how to split the local map by viewmodel and viewpose.


#### common data report method

1. keypoints, keyframes, searchable map.
2. the common space writers and readers. how to use unlock space. 
3. how to merge the maps by unlock space ?
4. mapping (lots of keypoints ... )select sub elementes, these keypoints how to split in a space by fast method (may < 1ms). research TSDF
5. the interface for the structure ... the struct can maintained these result and merge map and result, show on a screen, or create different result send to different depart. (like sameone contained tree same origize contain the forests.)
   1. callback for in data 
   2. callback get output