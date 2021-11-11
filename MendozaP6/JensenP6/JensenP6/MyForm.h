#pragma once
#include "Hand.h"
#include "Game.h"
#include "UtilityFunctions.h"

namespace JensenP6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	Game game;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			btPlay->Visible = false;
			btStay->Visible = false;
			btPlayGame->Visible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbHead;
	protected:
	private: System::Windows::Forms::Label^ lbRules;

	private: System::Windows::Forms::Label^ lbBet;
	private: System::Windows::Forms::Button^ btBet;
	private: System::Windows::Forms::TextBox^ txPlayer;
	private: System::Windows::Forms::Label^ lbPlayer;
	private: System::Windows::Forms::TextBox^ txDeal;
	private: System::Windows::Forms::Label^ lbDeal;
	private: System::Windows::Forms::TextBox^ txBet;
	private: System::Windows::Forms::Button^ btPlay;
	private: System::Windows::Forms::TextBox^ txResults;
	private: System::Windows::Forms::Label^ lbResults;
	private: System::Windows::Forms::Button^ btStay;
	private: System::Windows::Forms::Button^ btPlayGame;
	private: System::Windows::Forms::MenuStrip^ msRules;
	private: System::Windows::Forms::ToolStripMenuItem^ gameRulesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripTextBox^ toolStripTextBox1;
	private: System::Windows::Forms::Label^ lbCBS;
	private: System::Windows::Forms::TextBox^ txBS;
	private: System::Windows::Forms::Label^ lbDealBS;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ lbMon;
	private: System::Windows::Forms::TextBox^ txMon;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbHead = (gcnew System::Windows::Forms::Label());
			this->lbRules = (gcnew System::Windows::Forms::Label());
			this->lbBet = (gcnew System::Windows::Forms::Label());
			this->btBet = (gcnew System::Windows::Forms::Button());
			this->txPlayer = (gcnew System::Windows::Forms::TextBox());
			this->lbPlayer = (gcnew System::Windows::Forms::Label());
			this->txDeal = (gcnew System::Windows::Forms::TextBox());
			this->lbDeal = (gcnew System::Windows::Forms::Label());
			this->txBet = (gcnew System::Windows::Forms::TextBox());
			this->btPlay = (gcnew System::Windows::Forms::Button());
			this->txResults = (gcnew System::Windows::Forms::TextBox());
			this->lbResults = (gcnew System::Windows::Forms::Label());
			this->btStay = (gcnew System::Windows::Forms::Button());
			this->btPlayGame = (gcnew System::Windows::Forms::Button());
			this->msRules = (gcnew System::Windows::Forms::MenuStrip());
			this->gameRulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripTextBox1 = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->lbCBS = (gcnew System::Windows::Forms::Label());
			this->txBS = (gcnew System::Windows::Forms::TextBox());
			this->lbDealBS = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lbMon = (gcnew System::Windows::Forms::Label());
			this->txMon = (gcnew System::Windows::Forms::TextBox());
			this->msRules->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbHead
			// 
			this->lbHead->AutoSize = true;
			this->lbHead->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbHead->Location = System::Drawing::Point(137, 30);
			this->lbHead->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbHead->Name = L"lbHead";
			this->lbHead->Size = System::Drawing::Size(396, 36);
			this->lbHead->TabIndex = 0;
			this->lbHead->Text = L"Welcome to C++ BlackJack!";
			this->lbHead->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// lbRules
			// 
			this->lbRules->AutoSize = true;
			this->lbRules->Location = System::Drawing::Point(96, 78);
			this->lbRules->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbRules->Name = L"lbRules";
			this->lbRules->Size = System::Drawing::Size(476, 17);
			this->lbRules->TabIndex = 1;
			this->lbRules->Text = L"Press the \"Game Rules\" in the top left corner to see how to play the game.";
			// 
			// lbBet
			// 
			this->lbBet->AutoSize = true;
			this->lbBet->Location = System::Drawing::Point(113, 124);
			this->lbBet->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbBet->Name = L"lbBet";
			this->lbBet->Size = System::Drawing::Size(148, 17);
			this->lbBet->TabIndex = 3;
			this->lbBet->Text = L"Please enter your bet:";
			// 
			// btBet
			// 
			this->btBet->Location = System::Drawing::Point(480, 110);
			this->btBet->Margin = System::Windows::Forms::Padding(4);
			this->btBet->Name = L"btBet";
			this->btBet->Size = System::Drawing::Size(67, 44);
			this->btBet->TabIndex = 4;
			this->btBet->Text = L"Make Bet";
			this->btBet->UseVisualStyleBackColor = true;
			this->btBet->Click += gcnew System::EventHandler(this, &MyForm::btBet_Click);
			// 
			// txPlayer
			// 
			this->txPlayer->Location = System::Drawing::Point(51, 202);
			this->txPlayer->Margin = System::Windows::Forms::Padding(4);
			this->txPlayer->Multiline = true;
			this->txPlayer->Name = L"txPlayer";
			this->txPlayer->ReadOnly = true;
			this->txPlayer->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->txPlayer->Size = System::Drawing::Size(208, 117);
			this->txPlayer->TabIndex = 5;
			// 
			// lbPlayer
			// 
			this->lbPlayer->AutoSize = true;
			this->lbPlayer->Location = System::Drawing::Point(59, 171);
			this->lbPlayer->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbPlayer->Name = L"lbPlayer";
			this->lbPlayer->Size = System::Drawing::Size(86, 17);
			this->lbPlayer->TabIndex = 6;
			this->lbPlayer->Text = L"Player Hand";
			// 
			// txDeal
			// 
			this->txDeal->Location = System::Drawing::Point(292, 202);
			this->txDeal->Margin = System::Windows::Forms::Padding(4);
			this->txDeal->Multiline = true;
			this->txDeal->Name = L"txDeal";
			this->txDeal->ReadOnly = true;
			this->txDeal->Size = System::Drawing::Size(208, 117);
			this->txDeal->TabIndex = 7;
			// 
			// lbDeal
			// 
			this->lbDeal->AutoSize = true;
			this->lbDeal->Location = System::Drawing::Point(308, 171);
			this->lbDeal->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbDeal->Name = L"lbDeal";
			this->lbDeal->Size = System::Drawing::Size(88, 17);
			this->lbDeal->TabIndex = 8;
			this->lbDeal->Text = L"Dealer Hand";
			// 
			// txBet
			// 
			this->txBet->Location = System::Drawing::Point(292, 121);
			this->txBet->Margin = System::Windows::Forms::Padding(4);
			this->txBet->Name = L"txBet";
			this->txBet->Size = System::Drawing::Size(135, 22);
			this->txBet->TabIndex = 9;
			this->txBet->TextChanged += gcnew System::EventHandler(this, &MyForm::txBet_TextChanged);
			// 
			// btPlay
			// 
			this->btPlay->Location = System::Drawing::Point(523, 202);
			this->btPlay->Margin = System::Windows::Forms::Padding(4);
			this->btPlay->Name = L"btPlay";
			this->btPlay->Size = System::Drawing::Size(107, 55);
			this->btPlay->TabIndex = 10;
			this->btPlay->Text = L"Hit";
			this->btPlay->UseVisualStyleBackColor = true;
			this->btPlay->Click += gcnew System::EventHandler(this, &MyForm::btPlay_Click);
			// 
			// txResults
			// 
			this->txResults->Location = System::Drawing::Point(51, 370);
			this->txResults->Margin = System::Windows::Forms::Padding(4);
			this->txResults->Multiline = true;
			this->txResults->Name = L"txResults";
			this->txResults->ReadOnly = true;
			this->txResults->Size = System::Drawing::Size(240, 66);
			this->txResults->TabIndex = 11;
			// 
			// lbResults
			// 
			this->lbResults->AutoSize = true;
			this->lbResults->Location = System::Drawing::Point(59, 351);
			this->lbResults->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbResults->Name = L"lbResults";
			this->lbResults->Size = System::Drawing::Size(97, 17);
			this->lbResults->TabIndex = 12;
			this->lbResults->Text = L"Game Results";
			// 
			// btStay
			// 
			this->btStay->Location = System::Drawing::Point(523, 285);
			this->btStay->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btStay->Name = L"btStay";
			this->btStay->Size = System::Drawing::Size(107, 55);
			this->btStay->TabIndex = 13;
			this->btStay->Text = L"Stay";
			this->btStay->UseVisualStyleBackColor = true;
			this->btStay->Click += gcnew System::EventHandler(this, &MyForm::btStay_Click);
			// 
			// btPlayGame
			// 
			this->btPlayGame->Location = System::Drawing::Point(330, 370);
			this->btPlayGame->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btPlayGame->Name = L"btPlayGame";
			this->btPlayGame->Size = System::Drawing::Size(131, 46);
			this->btPlayGame->TabIndex = 14;
			this->btPlayGame->Text = L"Play Again";
			this->btPlayGame->UseVisualStyleBackColor = true;
			this->btPlayGame->Click += gcnew System::EventHandler(this, &MyForm::btPlayGame_Click);
			// 
			// msRules
			// 
			this->msRules->ImageScalingSize = System::Drawing::Size(20, 20);
			this->msRules->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->gameRulesToolStripMenuItem });
			this->msRules->Location = System::Drawing::Point(0, 0);
			this->msRules->Name = L"msRules";
			this->msRules->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->msRules->Size = System::Drawing::Size(683, 28);
			this->msRules->TabIndex = 15;
			this->msRules->Text = L"Rules";
			// 
			// gameRulesToolStripMenuItem
			// 
			this->gameRulesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			this->gameRulesToolStripMenuItem->Name = L"gameRulesToolStripMenuItem";
			this->gameRulesToolStripMenuItem->Size = System::Drawing::Size(101, 24);
			this->gameRulesToolStripMenuItem->Text = L"Game Rules";
			this->gameRulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::gameRulesToolStripMenuItem_Click);
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripTextBox1 });
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(225, 26);
			this->toolStripMenuItem1->Text = L"toolStripMenuItem1";
			// 
			// toolStripTextBox1
			// 
			this->toolStripTextBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->toolStripTextBox1->Name = L"toolStripTextBox1";
			this->toolStripTextBox1->Size = System::Drawing::Size(100, 27);
			// 
			// lbCBS
			// 
			this->lbCBS->AutoSize = true;
			this->lbCBS->Location = System::Drawing::Point(48, 323);
			this->lbCBS->Name = L"lbCBS";
			this->lbCBS->Size = System::Drawing::Size(132, 17);
			this->lbCBS->TabIndex = 16;
			this->lbCBS->Text = L"Current Best Score:";
			// 
			// txBS
			// 
			this->txBS->Location = System::Drawing::Point(204, 320);
			this->txBS->Name = L"txBS";
			this->txBS->ReadOnly = true;
			this->txBS->Size = System::Drawing::Size(55, 22);
			this->txBS->TabIndex = 17;
			this->txBS->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbDealBS
			// 
			this->lbDealBS->AutoSize = true;
			this->lbDealBS->Location = System::Drawing::Point(288, 323);
			this->lbDealBS->Name = L"lbDealBS";
			this->lbDealBS->Size = System::Drawing::Size(95, 17);
			this->lbDealBS->TabIndex = 18;
			this->lbDealBS->Text = L"Dealer Score:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(445, 320);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(55, 22);
			this->textBox1->TabIndex = 19;
			this->textBox1->Text = L"\?";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// lbMon
			// 
			this->lbMon->AutoSize = true;
			this->lbMon->Location = System::Drawing::Point(477, 385);
			this->lbMon->Name = L"lbMon";
			this->lbMon->Size = System::Drawing::Size(114, 17);
			this->lbMon->TabIndex = 20;
			this->lbMon->Text = L"Current Funds: $";
			// 
			// txMon
			// 
			this->txMon->Location = System::Drawing::Point(601, 385);
			this->txMon->Name = L"txMon";
			this->txMon->ReadOnly = true;
			this->txMon->Size = System::Drawing::Size(70, 22);
			this->txMon->TabIndex = 21;
			this->txMon->Text = L"1000";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::ForestGreen;
			this->ClientSize = System::Drawing::Size(683, 478);
			this->Controls->Add(this->txMon);
			this->Controls->Add(this->lbMon);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->lbDealBS);
			this->Controls->Add(this->txBS);
			this->Controls->Add(this->lbCBS);
			this->Controls->Add(this->btPlayGame);
			this->Controls->Add(this->btStay);
			this->Controls->Add(this->lbResults);
			this->Controls->Add(this->txResults);
			this->Controls->Add(this->btPlay);
			this->Controls->Add(this->txBet);
			this->Controls->Add(this->lbDeal);
			this->Controls->Add(this->txDeal);
			this->Controls->Add(this->lbPlayer);
			this->Controls->Add(this->txPlayer);
			this->Controls->Add(this->btBet);
			this->Controls->Add(this->lbBet);
			this->Controls->Add(this->lbRules);
			this->Controls->Add(this->lbHead);
			this->Controls->Add(this->msRules);
			this->ForeColor = System::Drawing::Color::Coral;
			this->MainMenuStrip = this->msRules;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Richard Jensen - Black Jack";
			this->msRules->ResumeLayout(false);
			this->msRules->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void txBet_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btBet_Click(System::Object^ sender, System::EventArgs^ e) {
	int bet;
	string betStr;
	To_string(txBet->Text, betStr);
	bet = stoi(betStr);
	string status;
	bool bBet{ false }, bJ{ false };
	
	
	bBet = game.SetBet(bet);
	if (!bBet)
	{
		status = " Error! something is wrong with your bet!";
		status.append("\n Please enter a new bet.");
		txResults->Text = gcnew String(status.c_str());
		
	}
	else
	{
		game.InitialDeal();
		txBS->Text = gcnew String(game.GetBest(false).c_str());
		txPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
		txDeal->Text = gcnew String(game.ShowDealersHand(false).c_str());
		bJ = game.IsBlackJack();
		if (!bJ)
		{
			btBet->Visible = false;
			txBet->Visible = false;
			lbBet->Visible = false;

			btPlay->Visible = true;
			btStay->Visible = true;
		}
		else
		{
			txDeal->Text = gcnew String(game.ShowDealersHand(true).c_str());
			txResults->Text = gcnew String(game.ShowResults().c_str());
			txBS->Text = gcnew String(game.GetBest(false).c_str());
			textBox1->Text = gcnew String(game.GetBest(true).c_str());


			btBet->Visible = false;
			txBet->Visible = false;
			lbBet->Visible = false;

			btPlayGame->Visible = true;
		}
	}
}
private: System::Void btPlay_Click(System::Object^ sender, System::EventArgs^ e) {
	bool notBust{ false },  bDealer{ false };
	
	game.PlayerHits();
	notBust = game.PlayerContinues();
	txPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
	txBS->Text = gcnew String(game.GetBest(false).c_str());
	
	
	if (notBust)
	{
		notBust = game.PlayerContinues();
	}
	else
	{
		
		txResults->Text = gcnew String(game.ShowResults().c_str());
		btPlay->Enabled = false;
		btStay->Enabled = false;
		txPlayer->Text = gcnew String(game.ShowPlayerHand().c_str());
		txDeal->Text = gcnew String(game.ShowDealersHand(true).c_str());
		textBox1->Text = gcnew String(game.GetBest(true).c_str());
		btPlayGame->Visible = true;
		txMon->Text = gcnew String(to_string(game.GetMon()).c_str());

	}
}

private: System::Void btStay_Click(System::Object^ sender, System::EventArgs^ e) {
	bool bDealer{ true };
	
	btStay->Enabled = false;
	btPlay->Enabled = false;
	do
	{
		txDeal->Text = gcnew String(game.ShowDealersHand(true).c_str());
		bDealer = game.DealerContinues();
	} while (bDealer);
	txResults->Text = gcnew String(game.ShowResults().c_str());
	textBox1->Text = gcnew String(game.GetBest(true).c_str());
	btPlayGame->Visible = true;
	setprecision(2);
	
	txMon->Text = gcnew String(to_string(game.GetMon()).c_str());

}
private: System::Void btPlayGame_Click(System::Object^ sender, System::EventArgs^ e) {
//Restart Button
	game.ClearHands();
	btBet->Visible = true;
	lbBet->Visible = true;
	txBet->Visible = true;

	btPlay->Enabled = true;
	btStay->Enabled = true;
	btPlay->Visible = false;
	btStay->Visible = false;
	btPlayGame->Visible = false;
	txBS->Clear();
	textBox1->Text = "?";
	txResults->Clear();
	txBet->Clear();
	txPlayer->Clear();
	txDeal->Clear();
}
private: System::Void gameRulesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ message = "\r\n You will start with $1000 to bet and you and the dealer will be dealt two cards.";
	message = message + "\r\n You will then total up the value of the cards in your hand. ";
	message = message + "\r\n Each number card is worth its number value while face cards(King, Jack,";
	message = message +	"\r\n and Queen) are worth 10 and the ace is worth 11 or 1 (Depending on if you bust or not).";
	message = message + "\r\n Your goal is to have a higher total value of cards than the dealer while not exceeding 21.";
	message = message + "\r\n Each turn you may either hit, which adds a card to your hand, or you can stay, at which";
	message = message + "\r\n point the dealer takes over. In the event that you go over 21, you bust and lose the game.";
	message = message + "\r\n If you are dealt and ace and a face card, you total 21 right away: BlackJack! This will give";
	message = message + "\r\n you give you 1.5 times your bet. If both the dealer and the user stay, the totals are compared";
	message = message + "\r\n and whoever has a higher value wins. If you beat the dealer you get your bet amount added to your";
	message = message + "\r\n total money.";

	MessageBox::Show(message);

}


};
}
