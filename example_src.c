#ifdef CONFIG_TWL4030_CORE
#define CONFIG_IRQ_DOMAIN
#endif

#ifndef CONFIG_SPARC
int of_platform_populate(int n){
	return 0;
}
#endif

#ifdef CONFIG_IRQ_DOMAIN		
int irq_domain_simple_ops = 1;
void irq_domain_add(int *ops){
	int irq = *ops; 
}
#endif

#ifdef CONFIG_TWL4030_CORE			
int twl_probe(int n){
	int *ops = NULL;
#ifdef CONFIG_OF_IRQ 				
	ops = &irq_domain_simple_ops;
#endif
	irq_domain_add(ops);
#ifdef CONFIG_OF_DEVICE				
	of_platform_populate(n);
#endif
	return 0;
}
#endif