// Copyright 2016-2018 mik14a / Admix Network. All Rights Reserved.

#pragma once

#include "Factories/Factory.h"
#include "Engine.h"
#include "RawMesh.h"
#include "DestructibleMesh.h"
#include "VoxelFactory.generated.h"

class USkeletalMesh;
class UStaticMesh;
class UVoxImportOption;
class UVoxel;
class UVoxel;
class UMaterialInterface;
struct FVox;

/**
 *
 */
UCLASS()
class UVoxelFactory : public UFactory
{
	GENERATED_BODY()

public:

	UVoxelFactory(const FObjectInitializer& ObjectInitializer);

	void PostInitProperties() override;

	virtual bool DoesSupportClass(UClass * Class) override;

	virtual UClass* ResolveSupportedClass() override;

	virtual UObject* FactoryCreateBinary(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn) override;

private:

	UStaticMesh* CreateStaticMesh(UObject* InParent, FName InName, EObjectFlags Flags, const FVox* Vox) const;

	USkeletalMesh* CreateSkeletalMesh(UObject* InParent, FName InName, EObjectFlags Flags, const FVox* Vox) const;

	UDestructibleMesh* CreateDestructibleMesh(UObject* InParent, FName InName, EObjectFlags Flags, const FVox* Vox) const;

	UVoxel* CreateVoxel(UObject* InParent, FName InName, EObjectFlags Flags, const FVox* Vox) const;

	UStaticMesh* BuildStaticMesh(UStaticMesh* OutStaticMesh, FRawMesh& RawMesh) const;

	UMaterialInterface* CreateMaterial(UObject* InParent, FName &InName, EObjectFlags Flags, const FVox* Vox) const;

protected:

	UPROPERTY()
	UVoxImportOption* ImportOption;
	bool bShowOption;
};
