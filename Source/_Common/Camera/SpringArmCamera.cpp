﻿#include "_Common.h"
#include "SpringArmCamera.h"


USpringArmCamera::USpringArmCamera( AActor* pActor )
:  UBaseCamera( pActor ) 
{
//	    bUsePawnControlRotation = false; // Camera does not rotate relative to arm
    m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	m_pTarget = m_pSpringArm;
	SetupAttachment( m_pSpringArm, USpringArmComponent::SocketName );

    m_pSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 0.0f), FRotator(-60.0f, 0.0f, 0.0f));
//	    m_pSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
    m_pSpringArm->RelativeRotation = FRotator(-45.f, 0.f, 0.f);
    m_pSpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
	//m_pSpringArm->SetRelativeLocationAndRotation(FVector(100.0f, 100.0f, 10.0f), FRotator(-45.0f, 3.24f, 0.0f));
    //m_pSpringArm->TargetArmLength = 700.f;
	//m_pSpringArm->bEnableCameraLag = true;
    //m_pSpringArm->CameraLagSpeed = 3.0f;
//		m_pSpringArm->SetRelativeRotation(FRotator(-50.f, 0.f, 0.f)); 
//	    m_pSpringArm->bAbsoluteRotation = true; // Don't want arm to rotate when character does
//	    m_pSpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level
//		m_pSpringArm->TargetArmLength = 800.0f;
    
    // Create a camera...
	if( pActor )
		m_pSpringArm->SetupAttachment( pActor->GetRootComponent() );
}



void USpringArmCamera::_Zoom( float fDelta )
{

}


float USpringArmCamera::GetLength()
{
	return m_pSpringArm->TargetArmLength;
}

void USpringArmCamera::SetLength( float fLength )
{
	m_pSpringArm->TargetArmLength = fLength;
}
