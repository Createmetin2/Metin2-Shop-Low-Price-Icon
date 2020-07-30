//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(SHOP_FREE_ICON)
	PyModule_AddIntConstant(poModule, "SHOP_FREE_ICON", true);
#else
	PyModule_AddIntConstant(poModule, "SHOP_FREE_ICON", false);
#endif