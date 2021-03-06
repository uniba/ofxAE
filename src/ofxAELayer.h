#pragma once

#include "ofxAEDef.h"
#include "TransformNode.h"
#include "ofxAEProperty.h"

OFX_AE_NAMESPACE_BEGIN

class Marker;
class LayerCap;

class Layer {
	friend class Loader;
public:
	Layer();
	void update();
	virtual void setPropertyFrame(int frame);
	void setParent(Layer *parent);
	Layer* getParent() { return parent_; }
	
	void setCap(LayerCap *cap) { cap_=cap; }
	LayerCap* getCap() { return cap_; }
	
	bool isActive() { return is_active_; }
	float getOpacity() { return opacity_; }
	TransformNode& getNode() { return transform_; }
	const string& getName() { return name_; }
	int getFrame() { return frame_; }

	void setActive(bool active);
	void setOpacity(float opacity) { opacity_=opacity; }
	void setTranslation(const ofVec3f& translation) { transform_.setTranslation(translation); }
	void setRotation(const ofVec3f& rotation) { transform_.setRotation(rotation); }
	void setOrientation(const ofVec3f& orientation) { transform_.setOrientation(orientation); }
	void setScale(const ofVec3f& scale) { transform_.setScale(scale); }
	void setAnchorPoint(const ofVec3f& anchor_point) { transform_.setAnchorPoint(anchor_point); }
	
	void addOpacityProperty(Property<float> *prop);
	void addActiveProperty(Property<bool> *prop);
	void addTransformProperty(TransformProperty *prop);
	
	void addProperty(PropertyBase *prop);
	void removeProperty(PropertyBase *prop);

	void setParamByComment(const string &comment);
	const string& getParam(const string &key);
protected:
	string name_;
	LayerCap *cap_;
	int frame_;

	Layer *parent_;
	float opacity_;
	bool is_active_;
	TransformNode transform_;
	int frame_offset_, frame_in_, frame_out_;
	vector<Marker*> marker_;
	vector<PropertyBase*> properties_;
	std::map<string, string> param_;
	
private:
	void setActiveCallback(const bool &active) { setActive(active); }
};

OFX_AE_NAMESPACE_END
/* EOF */