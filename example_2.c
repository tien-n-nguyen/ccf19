#define MAX_ORDER 11

#if defined(CONFIG_PPC_256K_PAGES)
#define PAGE_SHIFT      18
#endif
#if defined(CONFIG_PPC_16K_PAGES)
#define PAGE_SHIFT      14
#endif

#ifdef CONFIG_SLAB
#define KMALLOC_SHIFT_HIGH ((MAX_ORDER+PAGE_SHIFT-1)\
			<= 25 ? (MAX_ORDER + PAGE_SHIFT - 1) : 25)
#endif

#ifndef CONFIG_SLOB
int* kmalloc_caches[KMALLOC_SHIFT_HIGH + 1];
#endif

#ifdef CONFIG_LOCKDEP
static void init_node_lock_keys(int node) {
	int i;
	for (i = 1; i < PAGE_SHIFT + MAX_ORDER; i++) {
	//Patch: for (i = 1; i < KMALLOC_SHIFT_HIGH; i++){
		int* cache = kmalloc_caches[i];
		slab_set_lock_classes(node);
	}
}
#endif
static void cpuup_prepare(int node){
#ifdef CONFIG_NUMA
	node = 0;
#endif
	init_node_lock_keys(node);
}