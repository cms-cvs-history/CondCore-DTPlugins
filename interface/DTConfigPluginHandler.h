#ifndef DTConfigPluginHandler_H
#define DTConfigPluginHandler_H
/** \class DTConfigPluginHandler
 *
 *  Description:
 *       Class to hold configuration identifier for chambers
 *
 *  $Date: 2008/01/28 12:38:37 $
 *  $Revision: 1.3 $
 *  \author Paolo Ronchese INFN Padova
 *
 */

//----------------------
// Base Class Headers --
//----------------------
#include "CondFormats/DTObjects/interface/DTConfigAbstractHandler.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
//#include "CondFormats/DTObjects/interface/DTConfigList.h"
//#include "CondFormats/DTObjects/interface/DTConfigData.h"
//#include "CondCore/DBCommon/interface/TypedRef.h"

//#include "CondFormats/DTObjects/interface/DTKeyedConfig.h"
//#include "CondFormats/DataRecord/interface/DTKeyedConfigListRcd.h"
//#include "CondCore/DBOutputService/interface/KeyedElement.h"
//#include "CondCore/IOVService/interface/KeyList.h"
//#include "FWCore/Framework/interface/EventSetup.h"

//#include "FWCore/Framework/interface/ESHandle.h"
//class DTDBSession;

//---------------
// C++ Headers --
//---------------
#include <string>
#include <map>

//              ---------------------
//              -- Class Interface --
//              ---------------------

class DTConfigPluginHandler:public DTConfigAbstractHandler {

 public:

  /** Destructor
   */
  virtual ~DTConfigPluginHandler();

  /** Operations
   */
  /// build static object
  static void build();

  /// get content
  int get( const edm::EventSetup& context,
           int cfgId, const DTKeyedConfig*& obj );
  void getData( const edm::EventSetup& context,
                int cfgId, std::vector<std::string>& list );

  void purge();

  static int maxBrickNumber;
  static int maxStringNumber;
  static int maxByteNumber;

 private:

  /** Constructor
   */
  DTConfigPluginHandler();
  DTConfigPluginHandler( const DTConfigPluginHandler& x );
  const DTConfigPluginHandler& operator=( const DTConfigPluginHandler& x );

  typedef std::pair<int,const DTKeyedConfig*> counted_brick;
  std::map<int,counted_brick> brickMap;
  int cachedBrickNumber;
  int cachedStringNumber;
  int cachedByteNumber;

};

#endif // DTConfigPluginHandler_H


