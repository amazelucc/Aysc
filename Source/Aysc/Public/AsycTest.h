// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Http.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AsycTest.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMyTestDeleage);
UCLASS()
class AYSC_API UAsycTest : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
	
public :
	UFUNCTION(BlueprintCallable, Category = "Sanmu", meta = (BlueprintInernetnalUseronly = "true"))
		static UAsycTest *Login(FString ServerURL, FString UserName, FString Password);
	UPROPERTY(BlueprintAssignable)
		FMyTestDeleage OnLoginSuccess;
	UPROPERTY(BlueprintAssignable)
		FMyTestDeleage OnUserNameError;
	UPROPERTY(BlueprintAssignable)
		FMyTestDeleage OnPasswordError;
	UPROPERTY(BlueprintAssignable)
		FMyTestDeleage OnNetError;


	void PostLogin(FString ServerAddr, FString UserName, FString Password);
	void OnLoginComplete(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded);
		
	
	
	
};
