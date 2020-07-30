//Find
	Slot.pFinishCoolTimeEffect = NULL;
	
///Add
#if defined(SHOP_FREE_ICON)
	Slot.pInstanceFreeIcon = nullptr;
#endif

//Find
BOOL CSlotWindow::HasSlot(DWORD dwIndex)
{
	...
}

///Add
#if defined(SHOP_FREE_ICON)
void CSlotWindow::SetFreeIcon(DWORD dwIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(dwIndex, &pSlot) || pSlot->pInstanceFreeIcon)
		return;

	auto pImage = dynamic_cast<CGraphicImage*>(CResourceManager::Instance().GetResourcePointer("icon/free.png"));
	if (!pImage)
		return;

	pSlot->FreeIconState = true;
	pSlot->FreeIconStage = 1.0f;
	pSlot->FreeIconTime = ELTimer_GetMSec();

	pSlot->pInstanceFreeIcon = CGraphicImageInstance::New();
	pSlot->pInstanceFreeIcon->SetImagePointer(pImage);
}
#endif

//Find
	if (pSlot->pCoverButton)
	{
		pSlot->pCoverButton->Hide();
	}
	
///Add
#if defined(SHOP_FREE_ICON)
	if (pSlot->pInstanceFreeIcon) {
		CGraphicImageInstance::Delete(pSlot->pInstanceFreeIcon);
		pSlot->pInstanceFreeIcon = nullptr;
	}
#endif

//Find
		if (rSlot.pFinishCoolTimeEffect)
		{
			rSlot.pFinishCoolTimeEffect->SetPosition(rSlot.ixPosition, rSlot.iyPosition);
			rSlot.pFinishCoolTimeEffect->Update();
			rSlot.pFinishCoolTimeEffect->Render();
		}
		
///Add
#if defined(SHOP_FREE_ICON)
		if (rSlot.pInstanceFreeIcon) {
			if (ELTimer_GetMSec() - rSlot.FreeIconTime > 8) {
				if (rSlot.FreeIconState)
					rSlot.FreeIconStage -= 0.02f;
				else
					rSlot.FreeIconStage += 0.02f;

				if (rSlot.FreeIconState && rSlot.FreeIconStage <= 0.0f || !rSlot.FreeIconState && rSlot.FreeIconStage >= 1.0f)
					rSlot.FreeIconState = !rSlot.FreeIconState;

				rSlot.pInstanceFreeIcon->SetDiffuseColor(1.0, 1.0, 1.0, rSlot.FreeIconStage);
				rSlot.FreeIconTime = ELTimer_GetMSec();
			}
			rSlot.pInstanceFreeIcon->SetPosition(m_rect.left + rSlot.ixPosition + 14.0f, (m_rect.top + rSlot.iyPosition + rSlot.byyPlacedItemSize * ITEM_HEIGHT) - 17.0f);
			rSlot.pInstanceFreeIcon->Render();
		}
#endif