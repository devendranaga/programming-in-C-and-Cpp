#include <iostream>

class pc_builder {
	public:
		explicit pc_builder() { }
		~pc_builder() { }

		pc_builder &assemble_cpu() {
			std::cout << "cpu aseembling done" << std::endl;
			cpu_ = true;
			return *this;
		}

		pc_builder &assemble_gpu() {
			std::cout  << "gpu assembling done" << std::endl;
			gpu_ = true;
			return *this;
		}

		pc_builder &assemble_fan() {
			std::cout << "fan assemble done" << std::endl;
			fan_ = true;
			return *this;
		}

		pc_builder &assemble_ram() {
			std::cout << "ram assemble done" << std::endl;
			ram_ = true;
			return *this;
		}

		pc_builder &assemble_components() {
			std::cout << "aseembled rest of the components" << std::endl;
			components_ = true;
			return *this;
		}

		bool power_on() {
			std::cout << "power on ok" << std::endl;
			return true;
		}

	private:
		bool cpu_;
		bool gpu_;
		bool fan_;
		bool ram_;
		bool components_;
};

int main()
{
	pc_builder b;

	b.assemble_cpu()
	 .assemble_gpu()
	 .assemble_fan()
	 .assemble_ram()
	 .assemble_components();

	b.power_on();
}

