//Find
			void ClearSlot(DWORD dwIndex);
			
///Add
#if defined(SHOP_FREE_ICON)
			void SetFreeIcon(DWORD dwIndex);
#endif

//Find
				CGraphicImageInstance * pInstance;
				
///Add
#if defined(SHOP_FREE_ICON)
				CGraphicImageInstance* pInstanceFreeIcon;
				bool	FreeIconState;
				float	FreeIconStage;
				DWORD	FreeIconTime;
#endif