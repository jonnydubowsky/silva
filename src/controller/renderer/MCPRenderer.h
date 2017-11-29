//
// Created by Florian on 28.11.17.
//

#ifndef SILVA_MCPRENDERER_H
#define SILVA_MCPRENDERER_H

#include <controller/BaseController.h>
#include <util/PlatformConstants.h>
#include <Adafruit_MCP23017.h>
#include <model/Leaf.h>

#define MCP_PIN_COUNT 16

typedef Leaf* LeafPtr;

class MCPRenderer : public BaseController {
private:
    typedef Adafruit_MCP23017 *MCP23017Ptr;

    uint8_t mcpCount;

    LeafPtr *leafs;
    MCP23017Ptr *mcps;

    uint8_t minBrightness;
    uint8_t maxBrightness;

public:
    explicit MCPRenderer(uint8_t mcpCount, LeafPtr *leafs, uint8_t minBrightness = 0, uint8_t maxBrightness = 255);

    void setup() override;

    void loop() override;

    void render(LeafPtr leaf);
};


#endif //SILVA_MCPRENDERER_H
