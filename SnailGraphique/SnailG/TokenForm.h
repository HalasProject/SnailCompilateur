/**
	Salah Eddine Bentayeb
	GitHub.com/HalasProject
	FB | TWI | IG | @HalasDior
	Snail Compiler
	@version 1.0
*/

#pragma once
#include"Token.h"
#include "pch.h"
namespace SnailG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de TokenForm
	/// </summary>
	public ref class TokenForm : public System::Windows::Forms::Form
	{
	public:
		TokenForm(void)
		{
			InitializeComponent();
			debut();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~TokenForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NumT;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ParT;
	protected:



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TokenForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NumT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ParT = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlLightLight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->NumT, this->ParT });
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->Location = System::Drawing::Point(45, 39);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(442, 417);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &TokenForm::dataGridView1_CellContentClick);
			// 
			// NumT
			// 
			this->NumT->HeaderText = L"Num";
			this->NumT->Name = L"NumT";
			this->NumT->ReadOnly = true;
			this->NumT->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// ParT
			// 
			this->ParT->HeaderText = L"Parametre";
			this->ParT->Name = L"ParT";
			this->ParT->ReadOnly = true;
			this->ParT->Width = 300;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(387, 462);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 38);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &TokenForm::button1_Click);
			// 
			// TokenForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(532, 564);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"TokenForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Token";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		debut();
	}
	private: void debut() {
		Filo.close();
		Filo.open(PathGeneral);
		Token tok(Filo);
		std::vector<std::string> lol = tok.getVector();
		this->dataGridView1->Rows->Clear();
		for (split = 0; split < lol.size(); split++)
		{
			std::ostringstream convert;   // stream used for the conversion

			convert << split;      // insert the textual representation of 'Number' in the characters in the stream

			std::string Result = convert.str();
			std::string b = lol[split];
			
			String^ str2 = gcnew String(b.c_str());
			String^ str1 = gcnew String(Result.c_str());
			this->dataGridView1->Rows->Add(str1,str2);
		}
		Filo.close();
	}

	};
}
