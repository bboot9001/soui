#include "souistd.h"
#include "core/SSkinFactoryMgr.h"
#include "core/Sskin.h"

namespace SOUI
{

    void SSkinFactoryMgr::AddStandardSkin()
    {
        AddKeyObject(SSkinImgList::GetClassName(),new TplSkinFactory<SSkinImgList>);
        AddKeyObject(SSkinImgFrame::GetClassName(),new TplSkinFactory<SSkinImgFrame>);
        AddKeyObject(SSkinButton::GetClassName(),new TplSkinFactory<SSkinButton>);
        AddKeyObject(SSkinGradation::GetClassName(),new TplSkinFactory<SSkinGradation>);
        AddKeyObject(SSkinScrollbar::GetClassName(),new TplSkinFactory<SSkinScrollbar>);
        AddKeyObject(SSkinColorRect::GetClassName(),new TplSkinFactory<SSkinColorRect>);
    }

    void SSkinFactoryMgr::OnSkinRemoved( const SSkinFactoryPtr & obj )
    {
        delete obj;
    }

    ISkinObj * SSkinFactoryMgr::CreateSkinByName( LPCWSTR pszClassName )
    {
        if(!HasKey(pszClassName)) return NULL;
        return GetKeyObject(pszClassName)->NewSkin();
    }

}//end of namespace