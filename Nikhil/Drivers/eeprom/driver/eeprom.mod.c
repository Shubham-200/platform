#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xdcf391d5, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x550a9d21, __VMLINUX_SYMBOL_STR(i2c_del_driver) },
	{ 0x40e97f5d, __VMLINUX_SYMBOL_STR(i2c_register_driver) },
	{ 0xdac29194, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xfd174de4, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x7d400b92, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0xf7c633e, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0xe666c906, __VMLINUX_SYMBOL_STR(devm_kmalloc) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xbd4e52f9, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0xb7ee9d41, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x48fbe1ed, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x12da5bb2, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x4f357624, __VMLINUX_SYMBOL_STR(i2c_transfer) },
	{ 0xf9a482f9, __VMLINUX_SYMBOL_STR(msleep) },
	{ 0xe2e8065e, __VMLINUX_SYMBOL_STR(memdup_user) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xefd6cf06, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr0) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("i2c:eeprom");

MODULE_INFO(srcversion, "E655A2C72A857C68F667A95");
