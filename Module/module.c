#include <linux/module.h> 
#include <linux/kernel.h> 

int __init hello_init(void)
{
	pr_info("HELLO-MODULE: LOADED\n"); 
	return 0;
}

void __exit hello_cleanup(void)
{
	pr_info("HELLO-MODULE: UNLOAD\n");
}

module_init(hello_init);
module_exit(hello_cleanup); 
MODULE_LICENSE("GPLv2");
MODULE_DESCRIPTION("description");