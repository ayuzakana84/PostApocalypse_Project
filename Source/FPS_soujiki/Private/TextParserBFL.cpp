// Fill out your copyright notice in the Description page of Project Settings.


#include "TextParserBFL.h"

FString UTextParserBFL::GetTypewriterText(const FString& FullText, int32 VisibleCharCount)
{
	if (FullText.IsEmpty() || VisibleCharCount <= 0)
	{
		return FString("");
	}

	FString ResultString = "";
	int32 CurrentVisibleCount = 0;
	int32 i = 0;
	int32 OpenTagCount = 0;

	while (i < FullText.Len())
	{
		//色付け用のタグの始まり '<' を見つけた時
		if (FullText[i] == '<')
		{
			int32 TagEndIndex = -1;

			//対応するタグの終わり '>' を探す
			for (int32 j = i + 1; j < FullText.Len(); ++j)
			{
				if (FullText[j] == '>')
				{
					TagEndIndex = j;
					break;
				}
			}

			//'>' を見つけた場合、システム用のタグなので文字数にカウントしない
			if (TagEndIndex != -1)
			{
				if (i + 1 < FullText.Len() && FullText[i + 1] == '/')
				{
					OpenTagCount--;
				}
				else
				{
					OpenTagCount++;
				}

				ResultString += FullText.Mid(i, TagEndIndex - i + 1);
				i = TagEndIndex + 1;
				continue;
			}
		}

		
		if (CurrentVisibleCount < VisibleCharCount)
		{
			ResultString.AppendChar(FullText[i]);
			CurrentVisibleCount++;
			i++;
		}
		else
		{
			break;
		}
	}

	for (int32 k = 0; k < OpenTagCount; ++k)
	{
		ResultString += TEXT("</>");
	}

	return ResultString;
}