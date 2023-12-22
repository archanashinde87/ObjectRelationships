// Association.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <string>
#include <string_view>
#include <vector>

class Patient;

class Doctor
{
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};

public:
	Doctor(std::string_view name)
		:m_name{ name }
	{}

	void addPatient(Patient& patient);

	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string& getName() const { return m_name; }

};

class Patient
{
	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctor{};
	void addDoctor(const Doctor& doctor)
	{
		m_doctor.push_back(doctor);
	}
public:
	Patient(std::string_view name)
		:m_name{name}
	{}

	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);
	const std::string& getName() const { return m_name; }
	friend void Doctor::addPatient(Patient& patient);
};

void Doctor::addPatient(Patient& patient)
{
	m_patient.push_back(patient);
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Doctor& doctor)
{
	if (doctor.m_patient.empty())
	{
		out << doctor.m_name << " has no patients right now";
		return out;
	}

	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patient)
		out << patient.get().getName() << ' ';

	return out;
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
	if (patient.m_doctor.empty())
	{
		out << patient.getName() << " has no doctors right now";
		return out;
	}

	out << patient.m_name << " is seeing doctors: ";
	for (const auto& doctor : patient.m_doctor)
		out << doctor.get().getName() << ' ';

	return out;
}

int main()
{
	Patient arch{ "Archana" };
	Patient shanky{ "Shankar" };
	Patient yug{ "Yugan" };

	Doctor aniket{ "Aniket" };
	Doctor mugdha{ "Mugdha" };

	aniket.addPatient(arch);

	mugdha.addPatient(arch);
	mugdha.addPatient(yug);

	std::cout << aniket << '\n';
	std::cout << mugdha << '\n';
	std::cout << arch << '\n';
	std::cout << shanky << '\n';
	std::cout << yug << '\n';

	return 0;

}

