/*
 * Composite.hh
 *
 *  Created on: 3 d�c. 2008
 *      Author: yann
 */

#ifndef COMPOSITE_HH_
#define COMPOSITE_HH_

#include "ITSModel.hh"
#include "Type.hh"
#include "Naming.hh"
#include "Synchronization.hh"
#include "CState.hh"

namespace its {

class Composite : public NamedElement {
public :
  // subcomponents
  typedef std::vector<Instance> comps_t;
  typedef comps_t::const_iterator comps_it;
  // synchronizations
  typedef std::vector<Synchronization> syncs_t;
  typedef syncs_t::const_iterator syncs_it;
  // a private type to store a set of named composite states
  typedef std::map<vLabel,CState> cstates_t;
  typedef cstates_t::const_iterator cstates_it;
  
private :
  // instances contained 
  comps_t comps_;
  // syncs 
  syncs_t syncs_;
  // states
  cstates_t cstates_;
public :
  cstates_it cstates_begin() const { return cstates_.begin() ; }
  cstates_it cstates_end() const { return cstates_.end() ; }
  cstates_it cstates_find (Label lab) const { return cstates_.find(lab); }

  syncs_it syncs_begin() const { return syncs_.begin() ; }
  syncs_it syncs_end() const { return syncs_.end() ; }

  comps_it comps_begin() const { return comps_.begin() ; }
  comps_it comps_end() const { return comps_.end() ; }
  comps_it comps_find (Label iname) const { return findName(iname,comps_); }


  Composite (Label name) : NamedElement(name) {};
  virtual  ~Composite () {}
	/** Add an instance to this composite, returns false if instance name already exists,
	 * or if the type name is unknown in the model. Overloaded in TComposite.
	 */
  virtual bool addInstance (Label name, Label type_name, const ITSModel & model);
	/** Add a synchronization to this composite.
	 * Specify :
	 * name : the identifier of this transition
	 * label : the label of this synchronization, or the empty string "" if none (private synchronization)
	 */
  bool addSynchronization (Label sname, Label slabel);
	 /** A synchronization part : <instanceName,transitionLabel>. 
	  * Checks that the label exists in the instance are performed
	  */
    bool addSyncPart (Label sname, Label subnetname, Label tname);
    /** Set an assignment in a state.
     * Effect is: state(subnet) = substate
     * Will create the state if it does not exist, with default states for other instances. */
    bool updateStateDef (Label state, Label subnet, Label substate);

    virtual std::ostream & print (std::ostream & os) const ;
};


} // namespace

#endif /* COMPOSITE_HH_ */
