#Find in def Refresh(self):
			setItemID(i, getItemID(idx), itemCount)
			
#Add
			if app.SHOP_FREE_ICON:
				if shop.GetItemPrice(idx) < 500: #Edit Price
					self.itemSlotWindow.EnableShopFreeIcon(i)