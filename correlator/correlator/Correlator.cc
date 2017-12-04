#include "Correlator.h"
#include "correlator_likh.h"
#include <iomanip>
#include <stdexcept>
#include <iostream>
#include <fstream>
using namespace std;

Correlator::Correlator(std::shared_ptr<SystemDefinition> sysdef, std::string filename, std::vector<std::string> quantities, unsigned int timestep)
  : Logger(sysdef), m_sysdef(sysdef), m_fname(filename), m_quantities(quantities), m_corr()
  {
    assert(m_sysdef);
    assert(m_fname);
    assert(m_quantities);

    m_exec_conf->msg->notice(5) << "Constructing Correlator: "  << endl;
    // Correlator_Likh c;
    // m.setsize(32,16,2);
    // .initialize();
  }


void Correlator::analyze(unsigned int timestep)
  {
    setLoggedQuantities(m_quantities);
    Scalar value = this->getQuantity(m_quantities[0], timestep, false);

    // m_file.open(m_fname);
    // m_file << logged_quantity;



    c.add(value);

    ofstream m_file;
    if (!m_file.is_open())
      m_file.open(m_fname);

    if (timestep == 1000)
      cout <<timestep << endl;
      c.evaluate();
      cout<< c.npcorr << endl;
    // for (unsigned int i=0; i<c.npcorr;++i)
    //
    //   m_file << c.t[i] << " " << c.f[i] << endl;
      // m_file.close();



  }


void export_Correlator(pybind11::module& m)
  {
    pybind11::class_<Correlator, std::shared_ptr<Correlator>>(m, "Correlator", pybind11::base<Logger>())
      .def(pybind11::init< shared_ptr<SystemDefinition>, string , vector<std::string>, int  >());
  }
