// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintInsightsLibrary.generated.h"

/**
 * 
 */
UCLASS()
class BLUEPRINTINSIGHTS_API UBlueprintInsightsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/*
		* Pushing(Adding) cpu scope, recommended by Epic Games over SCOPED_NAMED_EVENT variant
		* WARNING: Do not try to add scope before delay and end it afterwards
		* WARNING: Each call must be paired with PopCPUEventScope
		* otherwise you scope will be endless or will be ended by someone else
		*/
	UFUNCTION(BlueprintCallable, Category = "Profiling", meta = (Keywords = "TRACE_CPUPROFILER_EVENT_SCOPE"))
	static void PushCPUEventScope(const FString& InName);

	UFUNCTION(BlueprintCallable, Category = "Profiling", meta = (Keywords = "TRACE_CPUPROFILER_EVENT_SCOPE"))
    static void PopCPUEventScope();

	/*
	 * Pushing(Adding) scope to the current profiler
	 * WARNING: Epic games recommend to use TRACE_CPUPROFILER_EVENT_SCOPE(PushCPUEventScope) instead
	 * WARNING: Do not try to add scope before delay and end it afterwards
	 * WARNING: Each call must be paired with PopScopedNamedEvent
	 * otherwise you scope will be endless or will be ended by someone else
	 */
	UFUNCTION(BlueprintCallable, Category = "Profiling", meta = (Keywords = "SCOPED_NAMED_EVENT"))
    static void PushScopedNamedEvent(const FColor& Color, const FString& InName);

	UFUNCTION(BlueprintCallable, Category = "Profiling", meta = (Keywords = "SCOPED_NAMED_EVENT"))
	static void PopScopedNamedEvent();
};
