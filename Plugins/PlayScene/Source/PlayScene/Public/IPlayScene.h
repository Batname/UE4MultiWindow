#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UTextureRenderTarget2D;


//-------------------------------------------------------------------------------------------------
// IPlayScene Module
//-------------------------------------------------------------------------------------------------

/**
 * The public interface to this module.  In most cases, this interface is only public to sibling modules
 * within this plugin.
 */
class IPlayScene : public IModuleInterface
{
public:

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed
	 */
	static inline IPlayScene& Get()
	{
		return FModuleManager::LoadModuleChecked< IPlayScene >("PlayScene");
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("PlayScene");
	}


public:
	/**
	* Get pointer to Texture render target
	* To make sure UTextureRenderTarget2D lifetime is controlled elsewhere, use "weak" ptr.
	* This is abstract fucntion and it need to be implemened
	*/
	virtual TWeakObjectPtr<UTextureRenderTarget2D> GetTextureRenderTarget2D() = 0;

	/**
	* Set UTextureRenderTarget2D to TWeakObjectPtr
	* This is abstract fucntion and it need to be implemened
	*/
	virtual void SetTextureRenderTarget2D(UTextureRenderTarget2D* TexRenderTarget2D) = 0;
};
