// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ct5108assignment_two/BoidManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoidManager() {}
// Cross Module References
	CT5108ASSIGNMENT_TWO_API UClass* Z_Construct_UClass_ABoidManager();
	CT5108ASSIGNMENT_TWO_API UClass* Z_Construct_UClass_ABoidManager_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ct5108assignment_two();
// End Cross Module References
	void ABoidManager::StaticRegisterNativesABoidManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoidManager);
	UClass* Z_Construct_UClass_ABoidManager_NoRegister()
	{
		return ABoidManager::StaticClass();
	}
	struct Z_Construct_UClass_ABoidManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnCount_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SpawnCount;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SpawnRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SpawnRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NeighbourRadius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NeighbourRadius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SeperationWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_SeperationWeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CohesionWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CohesionWeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentWeight_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_AlignmentWeight;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoidManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ct5108assignment_two,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BoidManager.h" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnCount_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnCount = { "SpawnCount", nullptr, (EPropertyFlags)0x0010000000004015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, SpawnCount), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnCount_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnCount_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnRadius_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnRadius = { "SpawnRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, SpawnRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnRadius_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_NeighbourRadius_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_NeighbourRadius = { "NeighbourRadius", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, NeighbourRadius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_NeighbourRadius_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_NeighbourRadius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_SeperationWeight_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_SeperationWeight = { "SeperationWeight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, SeperationWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_SeperationWeight_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_SeperationWeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_CohesionWeight_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_CohesionWeight = { "CohesionWeight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, CohesionWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_CohesionWeight_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_CohesionWeight_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoidManager_Statics::NewProp_AlignmentWeight_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "BoidManager.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABoidManager_Statics::NewProp_AlignmentWeight = { "AlignmentWeight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABoidManager, AlignmentWeight), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::NewProp_AlignmentWeight_MetaData), Z_Construct_UClass_ABoidManager_Statics::NewProp_AlignmentWeight_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABoidManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_SpawnRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_NeighbourRadius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_SeperationWeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_CohesionWeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABoidManager_Statics::NewProp_AlignmentWeight,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoidManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoidManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoidManager_Statics::ClassParams = {
		&ABoidManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABoidManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoidManager_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoidManager_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABoidManager()
	{
		if (!Z_Registration_Info_UClass_ABoidManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoidManager.OuterSingleton, Z_Construct_UClass_ABoidManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoidManager.OuterSingleton;
	}
	template<> CT5108ASSIGNMENT_TWO_API UClass* StaticClass<ABoidManager>()
	{
		return ABoidManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoidManager);
	ABoidManager::~ABoidManager() {}
	struct Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_BoidManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_BoidManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoidManager, ABoidManager::StaticClass, TEXT("ABoidManager"), &Z_Registration_Info_UClass_ABoidManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoidManager), 3351664919U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_BoidManager_h_48145337(TEXT("/Script/ct5108assignment_two"),
		Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_BoidManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_BoidManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
