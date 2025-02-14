#include <RendererFoundation/RendererFoundationPCH.h>

#include <RendererFoundation/Shader/ShaderByteCode.h>

ezGALShaderByteCode::ezGALShaderByteCode() = default;

ezGALShaderByteCode::ezGALShaderByteCode(const ezArrayPtr<const ezUInt8>& byteCode)
{
  CopyFrom(byteCode);
}

void ezGALShaderByteCode::CopyFrom(const ezArrayPtr<const ezUInt8>& pByteCode)
{
  EZ_ASSERT_DEV(pByteCode.GetPtr() != nullptr && pByteCode.GetCount() != 0, "Byte code is invalid!");

  m_Source = pByteCode;
}


