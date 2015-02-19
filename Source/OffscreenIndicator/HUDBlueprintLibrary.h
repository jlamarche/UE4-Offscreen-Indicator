// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "HUDBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OFFSCREENINDICATOR_API UHUDBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/**
	 * Converts a world location to screen position for HUD drawing. This differs from the results of FSceneView::WorldToScreen in that it returns a position along the edge of the screen for offscreen locations
	 *
	 * @param		InLocation	- The world space location to be converted to screen space
	 * @param		EdgePercent - How close to the edge of the screen, 1.0 = at edge, 0.0 = at center of screen. .9 or .95 is usually desirable
	 * @outparam	OutScreenPosition - the screen coordinates for HUD drawing
	 * @outparam	OutRotationAngleDegrees - The angle to rotate a hud element if you want it pointing toward the offscreen indicator, 0° if onscreen
	 * @outparam	bIsOnScreen - True if the specified location is in the camera view (may be obstructed)
	 */
	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject", CallableWithoutWorldContext), Category="HUD|Util")
	static void FindScreenEdgeLocationForWorldLocation(UObject* WorldContextObject, const FVector& InLocation, const float EdgePercent,  FVector2D& OutScreenPosition, float& OutRotationAngleDegrees, bool &bIsOnScreen);
	
	
};
