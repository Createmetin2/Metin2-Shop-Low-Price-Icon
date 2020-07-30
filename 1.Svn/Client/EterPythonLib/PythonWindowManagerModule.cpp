///Add
#if defined(SHOP_FREE_ICON)
PyObject* wndMgrSetFreeIcon(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin) || !pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &iSlotIndex))
		return Py_BuildException();

	dynamic_cast<UI::CSlotWindow*>(pWin)->SetFreeIcon(iSlotIndex);

	return Py_BuildNone();
}
#endif

//Find
		{ "AppendSlot",					wndMgrAppendSlot,					METH_VARARGS },
		
///Add
#if defined(SHOP_FREE_ICON)
		{ "SetFreeIcon",				wndMgrSetFreeIcon,					METH_VARARGS },
#endif