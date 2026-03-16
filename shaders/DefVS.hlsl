cbuffer cbuf {
    float4x4 MVP;
};

struct VSIn
{
    float3 pos : POSITION;
};

struct VSOut
{
    float4 pos : SV_Position;
};


VSOut main(VSIn input)
{
    VSOut output;
    output.pos = mul(MVP, float4(input.pos, 1.0f));
    return output;
}   