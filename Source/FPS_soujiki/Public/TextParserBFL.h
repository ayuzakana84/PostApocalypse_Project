// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextParserBFL.generated.h"

/**
 * 
 */
UCLASS()
class FPS_SOUJIKI_API UTextParserBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Custom UI|Text")
	static FString GetTypewriterText(const FString& FullText, int32 VisibleCharCount);
};
