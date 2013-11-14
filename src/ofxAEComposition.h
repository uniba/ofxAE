#pragma once

#include "ofConstants.h"
#include "ofFbo.h"
#include "FrameCounter.h"

namespace ofxAE {
	class AVLayer;
	class CameraLayer;
	class Marker;
}

namespace ofxAE {
class Composition {
	friend class Loader;
public:
	~Composition();
	void allocate(int width, int height);
	void setLength(int length);
	void update();
	void draw();
	void setFrame(int frame);
	void resetFrame(int frame);
	float getWidth() { return width_; }
	float getHeight() { return height_; }
	
	void addAVLayer(AVLayer *layer);
	int getNumAVLayer();
	vector<AVLayer*>& getAVLayers();
	AVLayer *getAVLayer(int index);
	AVLayer *getAVLayer(const string& name);
	
	void addCameraLayer(CameraLayer *layer);
	int getNumCameraLayer();
	vector<CameraLayer*>& getCameraLayers();
	CameraLayer *getCameraLayer(int index);
	CameraLayer *getCameraLayer(const string& name);
	
	void setActiveMarker(int index, float speed=1);
	void setActiveMarker(const string& name, float speed=1);
	void setActiveMarker(Marker *marker, float speed=1);
	void clearActiveMarker();
	
private:
	ofFbo fbo_;
	string name_;
	float width_;
	float height_;
	vector<AVLayer*> av_;
	vector<CameraLayer*> camera_;
	vector<Marker*> marker_;
	Marker *active_marker_;
	
	FrameCounter frame_;
	int length_default_;
private:
	void setPropertyFrame(int frame);
	void prepare();
};
	
	
inline void Composition::addAVLayer(AVLayer *layer)
{
	av_.push_back(layer);
}
inline int Composition::getNumAVLayer()
{
	return av_.size();
}
inline vector<AVLayer*>& Composition::getAVLayers()
{
	return av_;
}
inline AVLayer* Composition::getAVLayer(int index)
{
#ifdef _DEBUG
	if(index < 0 || index <= av_.size()) {
		return NULL;
	}
#endif
	return av_[index];
}


inline void Composition::addCameraLayer(CameraLayer *layer)
{
	camera_.push_back(layer);
}
inline int Composition::getNumCameraLayer()
{
	return camera_.size();
}
inline vector<CameraLayer*>& Composition::getCameraLayers()
{
	return camera_;
}
inline CameraLayer* Composition::getCameraLayer(int index)
{
#ifdef _DEBUG
	if(index < 0 || index <= camera_.size()) {
		return NULL;
	}
#endif
	return camera_[index];
}
}

/* EOF */