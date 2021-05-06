// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintInsightsLibrary.h"


void UBlueprintInsightsLibrary::PushCPUEventScope(const FString& InName)
{
	if (CpuChannel) // If CpuChannel is enabled
	{
		static uint32 EventId;                             
		EventId = FCpuProfilerTrace::OutputEventType(*InName);
	                                                   
        FCpuProfilerTrace::OutputBeginEvent(EventId);      
	}
}

void UBlueprintInsightsLibrary::PopCPUEventScope()
{
	if (CpuChannel) // If CpuChannel is enabled
	{
		FCpuProfilerTrace::OutputEndEvent();
	}
}

void UBlueprintInsightsLibrary::PushScopedNamedEvent(const FColor& Color, const FString& InName)
{
#if PLATFORM_IMPLEMENTS_BeginNamedEventStatic
	FPlatformMisc::BeginNamedEventStatic(Color, *InName);
#else
	FPlatformMisc::BeginNamedEvent(Color, *InName);
#endif
}

void UBlueprintInsightsLibrary::PopScopedNamedEvent()
{
	FPlatformMisc::EndNamedEvent();
}
