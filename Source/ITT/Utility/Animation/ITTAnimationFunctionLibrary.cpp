// Fill out your copyright notice in the Description page of Project Settings.


#include "ITTAnimationFunctionLibrary.h"


// ========== Anim Data ========== //
UAnimSequenceBase* UITTAnimationFunctionLibrary::GetRandomAnimAnimSequence(
	const FITTAnimSequencesData& AnimSequencesData)
{
	if (AnimSequencesData.AnimSequences.Num() == 0)
	{
		return nullptr;
	}
	
	float TotalProbability = 0.f;
	
	for (auto& Sequence : AnimSequencesData.AnimSequences)
	{
		TotalProbability += Sequence.Probability;
	}

	float RrandomValue = FMath::RandRange(0.f, TotalProbability);
	
	for (auto& Sequence : AnimSequencesData.AnimSequences)
	{
		RrandomValue -= Sequence.Probability;

		if (RrandomValue <= 0.f)
		{
			return Sequence.ObjectPtr;
		}
	}

	return AnimSequencesData.AnimSequences[0].ObjectPtr;
}
// =============================== //