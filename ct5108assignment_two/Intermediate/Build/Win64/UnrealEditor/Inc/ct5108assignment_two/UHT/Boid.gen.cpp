// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ct5108assignment_two/Boid.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoid() {}
// Cross Module References
	CT5108ASSIGNMENT_TWO_API UClass* Z_Construct_UClass_ABoid();
	CT5108ASSIGNMENT_TWO_API UClass* Z_Construct_UClass_ABoid_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_ct5108assignment_two();
// End Cross Module References
	void ABoid::StaticRegisterNativesABoid()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABoid);
	UClass* Z_Construct_UClass_ABoid_NoRegister()
	{
		return ABoid::StaticClass();
	}
	struct Z_Construct_UClass_ABoid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABoid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ct5108assignment_two,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Boid.h" },
		{ "ModuleRelativePath", "Boid.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABoid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABoid>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABoid_Statics::ClassParams = {
		&ABoid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams), Z_Construct_UClass_ABoid_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ABoid()
	{
		if (!Z_Registration_Info_UClass_ABoid.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABoid.OuterSingleton, Z_Construct_UClass_ABoid_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABoid.OuterSingleton;
	}
	template<> CT5108ASSIGNMENT_TWO_API UClass* StaticClass<ABoid>()
	{
		return ABoid::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoid);
	ABoid::~ABoid() {}
	struct Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_Boid_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_Boid_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABoid, ABoid::StaticClass, TEXT("ABoid"), &Z_Registration_Info_UClass_ABoid, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABoid), 3430430339U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_Boid_h_952910144(TEXT("/Script/ct5108assignment_two"),
		Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_Boid_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_s4204218_Documents_GitHub_ct5108assignmnet2_ct5108assignment_two_Source_ct5108assignment_two_Boid_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
