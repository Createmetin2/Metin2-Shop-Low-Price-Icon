#Find
	def SetSlotCount(self, slotNumber, count):
		wndMgr.SetSlotCount(self.hWnd, slotNumber, count)
		
#Add
	if app.SHOP_FREE_ICON:
		def EnableShopFreeIcon(self, renderingSlotNumber):
			wndMgr.SetFreeIcon(self.hWnd, renderingSlotNumber)