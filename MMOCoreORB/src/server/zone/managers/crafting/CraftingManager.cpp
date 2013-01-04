/*
 *	server/zone/managers/crafting/CraftingManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "CraftingManager.h"

#include "server/zone/objects/player/PlayerObject.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/manufactureschematic/ManufactureSchematic.h"

#include "server/zone/objects/draftschematic/DraftSchematic.h"

/*
 *	CraftingManagerStub
 */

enum {RPC_GETSCHEMATIC__INT_,RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_INT_,RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_INT_,RPC_CALCULATEASSEMBLYSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_,RPC_CALCULATEASSEMBLYVALUEMODIFIER__INT_,RPC_GETASSEMBLYPERCENTAGE__FLOAT_,RPC_CALCULATEEXPERIMENTATIONFAILURERATE__CREATUREOBJECT_MANUFACTURESCHEMATIC_INT_,RPC_CALCULATEEXPERIMENTATIONSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_,RPC_CALCULATEEXPERIMENTATIONVALUEMODIFIER__INT_INT_,RPC_GETWEIGHTEDVALUE__MANUFACTURESCHEMATIC_INT_,RPC_GENERATESERIAL__,RPC_CHECKBIOSKILLMODS__STRING_};

CraftingManager::CraftingManager() : ZoneManager(DummyConstructorParameter::instance()) {
	CraftingManagerImplementation* _implementation = new CraftingManagerImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("CraftingManager");
}

CraftingManager::CraftingManager(DummyConstructorParameter* param) : ZoneManager(param) {
	_setClassName("CraftingManager");
}

CraftingManager::~CraftingManager() {
}



void CraftingManager::initialize() {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->initialize();
}

void CraftingManager::awardSchematicGroup(PlayerObject* playerObject, Vector<String>& schematicgroups, bool updateClient) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->awardSchematicGroup(playerObject, schematicgroups, updateClient);
}

void CraftingManager::removeSchematicGroup(PlayerObject* playerObject, Vector<String>& schematicgroups, bool updateClient) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->removeSchematicGroup(playerObject, schematicgroups, updateClient);
}

DraftSchematic* CraftingManager::getSchematic(unsigned int schematicID) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSCHEMATIC__INT_);
		method.addUnsignedIntParameter(schematicID);

		return static_cast<DraftSchematic*>(method.executeWithObjectReturn());
	} else
		return _implementation->getSchematic(schematicID);
}

void CraftingManager::sendDraftSlotsTo(CreatureObject* player, unsigned int schematicID) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_INT_);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(schematicID);

		method.executeWithVoidReturn();
	} else
		_implementation->sendDraftSlotsTo(player, schematicID);
}

void CraftingManager::sendResourceWeightsTo(CreatureObject* player, unsigned int schematicID) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_INT_);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(schematicID);

		method.executeWithVoidReturn();
	} else
		_implementation->sendResourceWeightsTo(player, schematicID);
}

int CraftingManager::calculateAssemblySuccess(CreatureObject* player, DraftSchematic* draftSchematic, float effectiveness) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEASSEMBLYSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_);
		method.addObjectParameter(player);
		method.addObjectParameter(draftSchematic);
		method.addFloatParameter(effectiveness);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculateAssemblySuccess(player, draftSchematic, effectiveness);
}

float CraftingManager::calculateAssemblyValueModifier(int assemblyResult) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEASSEMBLYVALUEMODIFIER__INT_);
		method.addSignedIntParameter(assemblyResult);

		return method.executeWithFloatReturn();
	} else
		return _implementation->calculateAssemblyValueModifier(assemblyResult);
}

void CraftingManager::experimentRow(CraftingValues* craftingValues, int rowEffected, int pointsAttempted, float failure, int experimentationResult) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->experimentRow(craftingValues, rowEffected, pointsAttempted, failure, experimentationResult);
}

float CraftingManager::getAssemblyPercentage(float value) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETASSEMBLYPERCENTAGE__FLOAT_);
		method.addFloatParameter(value);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getAssemblyPercentage(value);
}

int CraftingManager::calculateExperimentationFailureRate(CreatureObject* player, ManufactureSchematic* manufactureSchematic, int pointsUsed) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEEXPERIMENTATIONFAILURERATE__CREATUREOBJECT_MANUFACTURESCHEMATIC_INT_);
		method.addObjectParameter(player);
		method.addObjectParameter(manufactureSchematic);
		method.addSignedIntParameter(pointsUsed);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculateExperimentationFailureRate(player, manufactureSchematic, pointsUsed);
}

int CraftingManager::calculateExperimentationSuccess(CreatureObject* player, DraftSchematic* draftSchematic, float effectiveness) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEEXPERIMENTATIONSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_);
		method.addObjectParameter(player);
		method.addObjectParameter(draftSchematic);
		method.addFloatParameter(effectiveness);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->calculateExperimentationSuccess(player, draftSchematic, effectiveness);
}

float CraftingManager::calculateExperimentationValueModifier(int experimentationResult, int pointsAttempted) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CALCULATEEXPERIMENTATIONVALUEMODIFIER__INT_INT_);
		method.addSignedIntParameter(experimentationResult);
		method.addSignedIntParameter(pointsAttempted);

		return method.executeWithFloatReturn();
	} else
		return _implementation->calculateExperimentationValueModifier(experimentationResult, pointsAttempted);
}

float CraftingManager::getWeightedValue(ManufactureSchematic* manufactureSchematic, int type) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETWEIGHTEDVALUE__MANUFACTURESCHEMATIC_INT_);
		method.addObjectParameter(manufactureSchematic);
		method.addSignedIntParameter(type);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getWeightedValue(manufactureSchematic, type);
}

String CraftingManager::generateSerial() {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GENERATESERIAL__);

		String _return_generateSerial;
		method.executeWithAsciiReturn(_return_generateSerial);
		return _return_generateSerial;
	} else
		return _implementation->generateSerial();
}

String CraftingManager::checkBioSkillMods(const String& property) {
	CraftingManagerImplementation* _implementation = static_cast<CraftingManagerImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CHECKBIOSKILLMODS__STRING_);
		method.addAsciiParameter(property);

		String _return_checkBioSkillMods;
		method.executeWithAsciiReturn(_return_checkBioSkillMods);
		return _return_checkBioSkillMods;
	} else
		return _implementation->checkBioSkillMods(property);
}

DistributedObjectServant* CraftingManager::_getImplementation() {

	 if (!_updated) _updated = true;
	return _impl;
}

void CraftingManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	CraftingManagerImplementation
 */

CraftingManagerImplementation::CraftingManagerImplementation(DummyConstructorParameter* param) : ZoneManagerImplementation(param) {
	_initializeImplementation();
}


CraftingManagerImplementation::~CraftingManagerImplementation() {
}


void CraftingManagerImplementation::finalize() {
}

void CraftingManagerImplementation::_initializeImplementation() {
	_setClassHelper(CraftingManagerHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void CraftingManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<CraftingManager*>(stub);
	ZoneManagerImplementation::_setStub(stub);
}

DistributedObjectStub* CraftingManagerImplementation::_getStub() {
	return _this.get();
}

CraftingManagerImplementation::operator const CraftingManager*() {
	return _this.get();
}

void CraftingManagerImplementation::lock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->lock(doLock);
}

void CraftingManagerImplementation::lock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->lock(obj);
}

void CraftingManagerImplementation::rlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->rlock(doLock);
}

void CraftingManagerImplementation::wlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->wlock(doLock);
}

void CraftingManagerImplementation::wlock(ManagedObject* obj) {
	_this.getReferenceUnsafeStaticCast()->wlock(obj);
}

void CraftingManagerImplementation::unlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->unlock(doLock);
}

void CraftingManagerImplementation::runlock(bool doLock) {
	_this.getReferenceUnsafeStaticCast()->runlock(doLock);
}

void CraftingManagerImplementation::_serializationHelperMethod() {
	ZoneManagerImplementation::_serializationHelperMethod();

	_setClassName("CraftingManager");

}

void CraftingManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(CraftingManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool CraftingManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ZoneManagerImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void CraftingManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = CraftingManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int CraftingManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ZoneManagerImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;

	return _count + 0;
}

CraftingManagerImplementation::CraftingManagerImplementation() : ZoneManagerImplementation("CraftingManager") {
	_initializeImplementation();
}

DraftSchematic* CraftingManagerImplementation::getSchematic(unsigned int schematicID) {
	// server/zone/managers/crafting/CraftingManager.idl():  		return schematicMap.get(schematicID);
	return schematicMap->get(schematicID);
}

/*
 *	CraftingManagerAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


CraftingManagerAdapter::CraftingManagerAdapter(CraftingManager* obj) : ZoneManagerAdapter(obj) {
}

void CraftingManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_GETSCHEMATIC__INT_:
		{
			resp->insertLong(getSchematic(inv->getUnsignedIntParameter())->_getObjectID());
		}
		break;
	case RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_INT_:
		{
			sendDraftSlotsTo(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getUnsignedIntParameter());
		}
		break;
	case RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_INT_:
		{
			sendResourceWeightsTo(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getUnsignedIntParameter());
		}
		break;
	case RPC_CALCULATEASSEMBLYSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_:
		{
			resp->insertSignedInt(calculateAssemblySuccess(static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<DraftSchematic*>(inv->getObjectParameter()), inv->getFloatParameter()));
		}
		break;
	case RPC_CALCULATEASSEMBLYVALUEMODIFIER__INT_:
		{
			resp->insertFloat(calculateAssemblyValueModifier(inv->getSignedIntParameter()));
		}
		break;
	case RPC_GETASSEMBLYPERCENTAGE__FLOAT_:
		{
			resp->insertFloat(getAssemblyPercentage(inv->getFloatParameter()));
		}
		break;
	case RPC_CALCULATEEXPERIMENTATIONFAILURERATE__CREATUREOBJECT_MANUFACTURESCHEMATIC_INT_:
		{
			resp->insertSignedInt(calculateExperimentationFailureRate(static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<ManufactureSchematic*>(inv->getObjectParameter()), inv->getSignedIntParameter()));
		}
		break;
	case RPC_CALCULATEEXPERIMENTATIONSUCCESS__CREATUREOBJECT_DRAFTSCHEMATIC_FLOAT_:
		{
			resp->insertSignedInt(calculateExperimentationSuccess(static_cast<CreatureObject*>(inv->getObjectParameter()), static_cast<DraftSchematic*>(inv->getObjectParameter()), inv->getFloatParameter()));
		}
		break;
	case RPC_CALCULATEEXPERIMENTATIONVALUEMODIFIER__INT_INT_:
		{
			resp->insertFloat(calculateExperimentationValueModifier(inv->getSignedIntParameter(), inv->getSignedIntParameter()));
		}
		break;
	case RPC_GETWEIGHTEDVALUE__MANUFACTURESCHEMATIC_INT_:
		{
			resp->insertFloat(getWeightedValue(static_cast<ManufactureSchematic*>(inv->getObjectParameter()), inv->getSignedIntParameter()));
		}
		break;
	case RPC_GENERATESERIAL__:
		{
			resp->insertAscii(generateSerial());
		}
		break;
	case RPC_CHECKBIOSKILLMODS__STRING_:
		{
			String property; 
			resp->insertAscii(checkBioSkillMods(inv->getAsciiParameter(property)));
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

DraftSchematic* CraftingManagerAdapter::getSchematic(unsigned int schematicID) {
	return (static_cast<CraftingManager*>(stub))->getSchematic(schematicID);
}

void CraftingManagerAdapter::sendDraftSlotsTo(CreatureObject* player, unsigned int schematicID) {
	(static_cast<CraftingManager*>(stub))->sendDraftSlotsTo(player, schematicID);
}

void CraftingManagerAdapter::sendResourceWeightsTo(CreatureObject* player, unsigned int schematicID) {
	(static_cast<CraftingManager*>(stub))->sendResourceWeightsTo(player, schematicID);
}

int CraftingManagerAdapter::calculateAssemblySuccess(CreatureObject* player, DraftSchematic* draftSchematic, float effectiveness) {
	return (static_cast<CraftingManager*>(stub))->calculateAssemblySuccess(player, draftSchematic, effectiveness);
}

float CraftingManagerAdapter::calculateAssemblyValueModifier(int assemblyResult) {
	return (static_cast<CraftingManager*>(stub))->calculateAssemblyValueModifier(assemblyResult);
}

float CraftingManagerAdapter::getAssemblyPercentage(float value) {
	return (static_cast<CraftingManager*>(stub))->getAssemblyPercentage(value);
}

int CraftingManagerAdapter::calculateExperimentationFailureRate(CreatureObject* player, ManufactureSchematic* manufactureSchematic, int pointsUsed) {
	return (static_cast<CraftingManager*>(stub))->calculateExperimentationFailureRate(player, manufactureSchematic, pointsUsed);
}

int CraftingManagerAdapter::calculateExperimentationSuccess(CreatureObject* player, DraftSchematic* draftSchematic, float effectiveness) {
	return (static_cast<CraftingManager*>(stub))->calculateExperimentationSuccess(player, draftSchematic, effectiveness);
}

float CraftingManagerAdapter::calculateExperimentationValueModifier(int experimentationResult, int pointsAttempted) {
	return (static_cast<CraftingManager*>(stub))->calculateExperimentationValueModifier(experimentationResult, pointsAttempted);
}

float CraftingManagerAdapter::getWeightedValue(ManufactureSchematic* manufactureSchematic, int type) {
	return (static_cast<CraftingManager*>(stub))->getWeightedValue(manufactureSchematic, type);
}

String CraftingManagerAdapter::generateSerial() {
	return (static_cast<CraftingManager*>(stub))->generateSerial();
}

String CraftingManagerAdapter::checkBioSkillMods(const String& property) {
	return (static_cast<CraftingManager*>(stub))->checkBioSkillMods(property);
}

/*
 *	CraftingManagerHelper
 */

CraftingManagerHelper* CraftingManagerHelper::staticInitializer = CraftingManagerHelper::instance();

CraftingManagerHelper::CraftingManagerHelper() {
	className = "CraftingManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void CraftingManagerHelper::finalizeHelper() {
	CraftingManagerHelper::finalize();
}

DistributedObject* CraftingManagerHelper::instantiateObject() {
	return new CraftingManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* CraftingManagerHelper::instantiateServant() {
	return new CraftingManagerImplementation();
}

DistributedObjectAdapter* CraftingManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CraftingManagerAdapter(static_cast<CraftingManager*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

