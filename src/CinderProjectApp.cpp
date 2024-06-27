#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/audio/Context.h"
#include "cinder/audio/GenNode.h"
#include "cinder/audio/GainNode.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CinderProjectApp : public App {
  public:
	void setup() override;
	void mouseDrag( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    audio::GenNodeRef    mGen;    // Gen's generate audio signals
    audio::GainNodeRef    mGain;    // Gain modifies the volume of the signal
};

void CinderProjectApp::setup()
{
    // You use the audio::Context to make new audio::Node instances (audio::master() is the speaker-facing Context).
    auto ctx = audio::master();
    //auto output = ctx->getOutput();

    mGen = ctx->makeNode( new audio::GenSineNode );
    mGain = ctx->makeNode( new audio::GainNode );

    mGen->setFreq( 220 );
    mGain->setValue( 0.5f );

    // connections can be made this way or with connect(). The master Context's getOutput() is the speakers by default.
    mGen >> mGain >> ctx->getOutput();

    // Node's need to be enabled to process audio. EffectNode's are enabled by default, while NodeSource's (like Gen) need to be switched on.
    mGen->enable();

    // Context also must be started. Starting and stopping this controls the entire DSP graph.
    ctx->enable();
}

void CinderProjectApp::mouseDrag( MouseEvent event )
{
    mGen->setFreq( event.getPos().x );
    mGain->setValue( 1.0f - (float)event.getPos().y / (float)getWindowHeight() );
}

void CinderProjectApp::update()
{

}

void CinderProjectApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    
    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            vec2 pt1(30 * x, 25 * y);
            gl::color( x * 0.08f, y * 0.05f, (x + y) * 0.18f );
            gl::drawSolidCircle(pt1, 5.0f );
        }
    }

}

CINDER_APP( CinderProjectApp, RendererGl )
