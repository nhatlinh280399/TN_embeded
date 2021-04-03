#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xc79d2779, "module_layout" },
	{ 0xc53c710a, "i2c_del_driver" },
	{ 0x783e551a, "i2c_unregister_device" },
	{ 0x1dcd1d4d, "i2c_put_adapter" },
	{ 0x76ff31e2, "i2c_register_driver" },
	{ 0x8a8ec4c9, "i2c_new_device" },
	{ 0x6bc19f59, "i2c_get_adapter" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xdefe8f15, "i2c_transfer_buffer_flags" },
	{ 0xc5850110, "printk" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("i2c:PCA9685");

MODULE_INFO(srcversion, "EBD2DE86364D1E880B017FB");
