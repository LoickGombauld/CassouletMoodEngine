#pragma once
#include <CassouletMoodEngineLibrarie/Export.h>
#include <CassouletMoodEngineLibrarie/DataTypes.h>
#include <CassouletMoodEngineLibrarie/Angle.h>
#include <CassouletMoodEngineLibrarie/ViewRenderer.h>

#include <CassouletMoodEngineLibrarie/Weapon.h>

class CASSOULET_DLL Player
{
public:
    Player(ViewRenderer* pViewRenderer, int iID);
    ~Player();

    void Init(Thing thing);
    void SetXPosition(int XPosition);
    void SetYPosition(int YPosition);
    void SetZPosition(int ZPosition);
    void SetAngle(int Angle);
    void MoveForward();
    void MoveBackward();
    void RotateLeft();
    void RotateRight();
    void Fly();
    void Sink();
    void Think(int iSubSectorHeight);
    void Render(uint8_t* pScreenBuffer, int iBufferPitch);
    void UpdateInput(const uint8_t* ,int width,int height);

    int GetID();
    int GetXPosition();
    int GetYPosition();
    int GetZPosition();
    int GetFOV();

    bool ClipVertexesInFOV(Vertex& V1, Vertex& V2, Angle& V1Angle, Angle& V2Angle, Angle& V1AngleFromPlayer, Angle& V2AngleFromPlayer);

    // Calulate the distance between the player an the vertex.
    float DistanceToPoint(Vertex& V);

    Angle AngleToVertex(Vertex& vertex);
    Angle GetAngle();

protected:
    int m_iPlayerID;
    float m_XPosition;
    float m_YPosition;
    int m_ZPosition;
    int m_EyeLevel;
    int m_FOV;
    int m_iRotationSpeed;
    int m_iMoveSpeed;
    int xMouse, yMouse;
    Angle m_Angle;
    Angle m_HalfFOV;
    ViewRenderer* m_pViewRenderer;
    std::unique_ptr <Weapon> m_pWeapon;
};
