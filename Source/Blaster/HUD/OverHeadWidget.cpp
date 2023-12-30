#include "OverHeadWidget.h"
#include "Components/TextBlock.h"

void UOverHeadWidget::SetDisplayText(FString TextToDisplay)
{
    if (DisplayText)
    {
	    DisplayText->SetText(FText::FromString(TextToDisplay));
    }
}


void UOverHeadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_Authority:
		Role = FString("Authority");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		Role = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		Role = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_None:
		Role = FString("None");
		break;
	}
	SetDisplayText(FString::Printf(TEXT("Remote Role: %s"), *Role));
}

void UOverHeadWidget::NativeDestruct()
{
    RemoveFromParent();
    Super::NativeDestruct();
}
