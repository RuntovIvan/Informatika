#pragma once
#include "Tree.h"
#include "Binary_Tree.h"

namespace BinaryTree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для TreeDraw
	/// </summary>
	public ref class TreeDraw : public System::Windows::Forms::Form
	{
	public:
		TreeDraw(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TreeDraw()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_to_draw;
	private: System::Windows::Forms::Button^ btn_insert;
	private: System::Windows::Forms::Button^ btn_erase;
	private: System::Windows::Forms::Button^ btn_find;
	private: System::Windows::Forms::Button^ btn_preorder;
	private: System::Windows::Forms::Button^ btn_inorder;
	private: System::Windows::Forms::Button^ btn_postorder;
	private: System::Windows::Forms::Button^ btn_balance;
	private: System::Windows::Forms::Button^ btn_clear;
	protected:
	private: System::Windows::Forms::Button^ btn_min;

	private: System::Windows::Forms::Label^ label_traversal;
	private: System::Windows::Forms::TextBox^ textBox_insert;
	private: System::Windows::Forms::TextBox^ textBox_erase;
	private: System::Windows::Forms::TextBox^ textBox_find;
	private: System::Windows::Forms::TextBox^ textBox_traversal;
	private: System::Windows::Forms::Label^ label_search;
		   
	private:
		Binary_Tree* tree = new Binary_Tree;
		float rad = 15;
		double shift_x = 30;
		double shift_y = 25;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TreeDraw::typeid));
			this->panel_to_draw = (gcnew System::Windows::Forms::Panel());
			this->btn_insert = (gcnew System::Windows::Forms::Button());
			this->btn_erase = (gcnew System::Windows::Forms::Button());
			this->btn_find = (gcnew System::Windows::Forms::Button());
			this->btn_preorder = (gcnew System::Windows::Forms::Button());
			this->btn_inorder = (gcnew System::Windows::Forms::Button());
			this->btn_postorder = (gcnew System::Windows::Forms::Button());
			this->btn_balance = (gcnew System::Windows::Forms::Button());
			this->btn_clear = (gcnew System::Windows::Forms::Button());
			this->btn_min = (gcnew System::Windows::Forms::Button());
			this->label_traversal = (gcnew System::Windows::Forms::Label());
			this->textBox_insert = (gcnew System::Windows::Forms::TextBox());
			this->textBox_erase = (gcnew System::Windows::Forms::TextBox());
			this->textBox_find = (gcnew System::Windows::Forms::TextBox());
			this->textBox_traversal = (gcnew System::Windows::Forms::TextBox());
			this->label_search = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel_to_draw
			// 
			this->panel_to_draw->BackColor = System::Drawing::Color::White;
			this->panel_to_draw->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_to_draw->Location = System::Drawing::Point(10, 10);
			this->panel_to_draw->Name = L"panel_to_draw";
			this->panel_to_draw->Size = System::Drawing::Size(1360, 600);
			this->panel_to_draw->TabIndex = 0;
			// 
			// btn_insert
			// 
			this->btn_insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_insert->Location = System::Drawing::Point(10, 650);
			this->btn_insert->Name = L"btn_insert";
			this->btn_insert->Size = System::Drawing::Size(150, 35);
			this->btn_insert->TabIndex = 1;
			this->btn_insert->Text = L"Вставить узел";
			this->btn_insert->UseVisualStyleBackColor = true;
			this->btn_insert->Click += gcnew System::EventHandler(this, &TreeDraw::btn_insert_Click);
			// 
			// btn_erase
			// 
			this->btn_erase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_erase->Location = System::Drawing::Point(170, 650);
			this->btn_erase->Name = L"btn_erase";
			this->btn_erase->Size = System::Drawing::Size(150, 35);
			this->btn_erase->TabIndex = 2;
			this->btn_erase->Text = L"Удалить узел";
			this->btn_erase->UseVisualStyleBackColor = true;
			this->btn_erase->Click += gcnew System::EventHandler(this, &TreeDraw::btn_erase_Click);
			// 
			// btn_find
			// 
			this->btn_find->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_find->Location = System::Drawing::Point(360, 650);
			this->btn_find->Name = L"btn_find";
			this->btn_find->Size = System::Drawing::Size(150, 35);
			this->btn_find->TabIndex = 3;
			this->btn_find->Text = L"По значению";
			this->btn_find->UseVisualStyleBackColor = true;
			this->btn_find->Click += gcnew System::EventHandler(this, &TreeDraw::btn_find_Click);
			// 
			// btn_preorder
			// 
			this->btn_preorder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_preorder->Location = System::Drawing::Point(710, 650);
			this->btn_preorder->Name = L"btn_preorder";
			this->btn_preorder->Size = System::Drawing::Size(150, 35);
			this->btn_preorder->TabIndex = 4;
			this->btn_preorder->Text = L"Прямой";
			this->btn_preorder->UseVisualStyleBackColor = true;
			this->btn_preorder->Click += gcnew System::EventHandler(this, &TreeDraw::btn_preorder_Click);
			// 
			// btn_inorder
			// 
			this->btn_inorder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_inorder->Location = System::Drawing::Point(870, 650);
			this->btn_inorder->Name = L"btn_inorder";
			this->btn_inorder->Size = System::Drawing::Size(150, 35);
			this->btn_inorder->TabIndex = 5;
			this->btn_inorder->Text = L"Симметричный";
			this->btn_inorder->UseVisualStyleBackColor = true;
			this->btn_inorder->Click += gcnew System::EventHandler(this, &TreeDraw::btn_inorder_Click);
			// 
			// btn_postorder
			// 
			this->btn_postorder->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_postorder->Location = System::Drawing::Point(1030, 650);
			this->btn_postorder->Name = L"btn_postorder";
			this->btn_postorder->Size = System::Drawing::Size(150, 35);
			this->btn_postorder->TabIndex = 6;
			this->btn_postorder->Text = L"Обратный";
			this->btn_postorder->UseVisualStyleBackColor = true;
			this->btn_postorder->Click += gcnew System::EventHandler(this, &TreeDraw::btn_postorder_Click);
			// 
			// btn_balance
			// 
			this->btn_balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_balance->Location = System::Drawing::Point(1220, 650);
			this->btn_balance->Name = L"btn_balance";
			this->btn_balance->Size = System::Drawing::Size(150, 50);
			this->btn_balance->TabIndex = 7;
			this->btn_balance->Text = L"Сбалансировать";
			this->btn_balance->UseVisualStyleBackColor = true;
			this->btn_balance->Click += gcnew System::EventHandler(this, &TreeDraw::btn_balance_Click);
			// 
			// btn_clear
			// 
			this->btn_clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_clear->Location = System::Drawing::Point(1220, 710);
			this->btn_clear->Name = L"btn_clear";
			this->btn_clear->Size = System::Drawing::Size(150, 50);
			this->btn_clear->TabIndex = 8;
			this->btn_clear->Text = L"Удалить дерево";
			this->btn_clear->UseVisualStyleBackColor = true;
			this->btn_clear->Click += gcnew System::EventHandler(this, &TreeDraw::btn_clear_Click);
			// 
			// btn_min
			// 
			this->btn_min->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_min->Location = System::Drawing::Point(520, 650);
			this->btn_min->Name = L"btn_min";
			this->btn_min->Size = System::Drawing::Size(150, 35);
			this->btn_min->TabIndex = 9;
			this->btn_min->Text = L"Минимальный";
			this->btn_min->UseVisualStyleBackColor = true;
			this->btn_min->Click += gcnew System::EventHandler(this, &TreeDraw::btn_min_Click);
			// 
			// label_traversal
			// 
			this->label_traversal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_traversal->Location = System::Drawing::Point(710, 620);
			this->label_traversal->Name = L"label_traversal";
			this->label_traversal->Size = System::Drawing::Size(470, 20);
			this->label_traversal->TabIndex = 10;
			this->label_traversal->Text = L"Обход";
			this->label_traversal->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_insert
			// 
			this->textBox_insert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_insert->Location = System::Drawing::Point(10, 700);
			this->textBox_insert->Name = L"textBox_insert";
			this->textBox_insert->Size = System::Drawing::Size(150, 24);
			this->textBox_insert->TabIndex = 11;
			// 
			// textBox_erase
			// 
			this->textBox_erase->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_erase->Location = System::Drawing::Point(170, 700);
			this->textBox_erase->Name = L"textBox_erase";
			this->textBox_erase->Size = System::Drawing::Size(150, 24);
			this->textBox_erase->TabIndex = 12;
			// 
			// textBox_find
			// 
			this->textBox_find->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_find->Location = System::Drawing::Point(360, 700);
			this->textBox_find->Name = L"textBox_find";
			this->textBox_find->Size = System::Drawing::Size(150, 24);
			this->textBox_find->TabIndex = 13;
			// 
			// textBox_traversal
			// 
			this->textBox_traversal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_traversal->Location = System::Drawing::Point(710, 700);
			this->textBox_traversal->Multiline = true;
			this->textBox_traversal->Name = L"textBox_traversal";
			this->textBox_traversal->Size = System::Drawing::Size(470, 60);
			this->textBox_traversal->TabIndex = 15;
			// 
			// label_search
			// 
			this->label_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_search->Location = System::Drawing::Point(360, 620);
			this->label_search->Name = L"label_search";
			this->label_search->Size = System::Drawing::Size(310, 20);
			this->label_search->TabIndex = 16;
			this->label_search->Text = L"Найти";
			this->label_search->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// TreeDraw
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1382, 803);
			this->Controls->Add(this->label_search);
			this->Controls->Add(this->textBox_traversal);
			this->Controls->Add(this->textBox_find);
			this->Controls->Add(this->textBox_erase);
			this->Controls->Add(this->textBox_insert);
			this->Controls->Add(this->label_traversal);
			this->Controls->Add(this->btn_min);
			this->Controls->Add(this->btn_clear);
			this->Controls->Add(this->btn_balance);
			this->Controls->Add(this->btn_postorder);
			this->Controls->Add(this->btn_inorder);
			this->Controls->Add(this->btn_preorder);
			this->Controls->Add(this->btn_find);
			this->Controls->Add(this->btn_erase);
			this->Controls->Add(this->btn_insert);
			this->Controls->Add(this->panel_to_draw);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TreeDraw";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TreeDraw";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// отрисовка
	// отрисовка ребер
	private: System::Void draw_edges(Tree* root, Pen^ pen)
	{
		if (root == nullptr)
			return;
		if (root->parent != nullptr)
		{
			Graphics^ g = panel_to_draw->CreateGraphics();
			g->DrawLine(pen, root->parent->x, root->parent->y, root->x, root->y);
			delete g;
		}
		draw_edges(root->left, pen);
		draw_edges(root->right, pen);
	}

	// отрисовка кругов без поиска
	private: System::Void draw_circles_normal(Tree* root, SolidBrush^ brush, Pen^ pen, float rad)
	{
		if (root == nullptr)
			return;

		Graphics^ g = panel_to_draw->CreateGraphics();
		g->FillEllipse(brush, root->x - rad, root->y - rad, rad * 2, rad * 2);
		g->DrawEllipse(pen, root->x - rad, root->y - rad, rad * 2, rad * 2);
		delete g;

		draw_circles_normal(root->left, brush, pen, rad);
		draw_circles_normal(root->right, brush, pen, rad);
	}

	// отрисовка кругов с поиском
	private: System::Void draw_circles_search(Tree* root, Tree* found, SolidBrush^ brush, Pen^ pen, float rad)
	{
		if (root == nullptr)
			return;

		Color origin_brush_col = brush->Color;
		if (root == found)
			brush->Color = Color::Green;

		Graphics^ g = panel_to_draw->CreateGraphics();
		g->FillEllipse(brush, root->x - rad, root->y - rad, rad * 2, rad * 2);
		g->DrawEllipse(pen, root->x - rad, root->y - rad, rad * 2, rad * 2);
		delete g;

		brush->Color = origin_brush_col;

		draw_circles_search(root->left, found, brush, pen, rad);
		draw_circles_search(root->right, found, brush, pen, rad);
	}

	// отрисовка данных
	private: System::Void draw_data(Tree* root, SolidBrush^ brush, float rad)
	{
		if (root == nullptr)
			return;

		String^ str = System::Convert::ToString(root->data);
		Graphics^ g = panel_to_draw->CreateGraphics();

		float font_size = std::max(rad / (str->Length), static_cast<float>(10));
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", font_size);
		SizeF^ text_size = g->MeasureString(str, font);
		float text_x = root->x - text_size->Width / 2;
		float text_y = root->y - text_size->Height / 2;

		g->DrawString(str, font, brush, text_x, text_y);
		delete g, str, font, text_size;

		draw_data(root->left, brush, rad);
		draw_data(root->right, brush, rad);
	}

	// отрисовка дерева без поиска
	private: System::Void draw_tree_normal(Binary_Tree* tree)
	{
		Graphics^ g = panel_to_draw->CreateGraphics();
		g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBilinear;
		g->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
		g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		tree->set_coords(panel_to_draw->Width, panel_to_draw->Height, shift_x);
		panel_to_draw->Controls->Clear();
		panel_to_draw->Refresh();

		Pen^ pen = gcnew Pen(Color::Black);
		SolidBrush^ brush_circle = gcnew SolidBrush(Color::Red);
		SolidBrush^ brush_text = gcnew SolidBrush(Color::White);

		rad = (panel_to_draw->Height - 2 * shift_y) / (2 * tree->root->get_height()) * (0.75);

		draw_edges(tree->root, pen);
		draw_circles_normal(tree->root, brush_circle, pen, rad);
		draw_data(tree->root, brush_text, rad);

		delete g, pen, brush_circle, brush_text;
	}

	// отрисовка дерева с поиском
	private: System::Void draw_tree_search(Binary_Tree* tree, Tree* found)
	{
		Graphics^ g = panel_to_draw->CreateGraphics();
		g->InterpolationMode = System::Drawing::Drawing2D::InterpolationMode::HighQualityBilinear;
		g->CompositingQuality = System::Drawing::Drawing2D::CompositingQuality::HighQuality;
		g->PixelOffsetMode = System::Drawing::Drawing2D::PixelOffsetMode::HighQuality;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		tree->set_coords(panel_to_draw->Width, panel_to_draw->Height, shift_x);
		panel_to_draw->Controls->Clear();
		panel_to_draw->Refresh();

		Pen^ pen = gcnew Pen(Color::Black);
		SolidBrush^ brush_circle = gcnew SolidBrush(Color::Red);
		SolidBrush^ brush_text = gcnew SolidBrush(Color::White);

		rad = (panel_to_draw->Height - 2 * shift_y) / (2 * tree->root->get_height()) * (0.75);

		draw_edges(tree->root, pen);
		draw_circles_search(tree->root, found, brush_circle, pen, rad);
		draw_data(tree->root, brush_text, rad);

		delete g, pen, brush_circle, brush_text;
	}

// формирование строк для обхода
	// строка прямого обхода
	private: System::Void make_preorderString(Tree* root, String^& str)
	{
		if (root != nullptr)
		{
			str += System::Convert::ToString(root->data) + " ";
			make_preorderString(root->left, str);
			make_preorderString(root->right, str);
		}
	}
	
	// строка симметричного обхода
	private: System::Void make_inorderString(Tree* root, String^& str)
	{
		if (root != nullptr)
		{
			make_inorderString(root->left, str);
			str += System::Convert::ToString(root->data) + " ";
			make_inorderString(root->right, str);
		}
	}

	// строка обратного обхода
	private: System::Void make_postorderString(Tree* root, String^& str)
	{
		if (root != nullptr)
		{
			make_postorderString(root->left, str);
			make_postorderString(root->right, str);
			str += System::Convert::ToString(root->data) + " ";
		}
	}

// действия при нажатии кнопок
	// кнопка добавления элемента
	private: System::Void btn_insert_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox_insert->Text->Length == 0)
		{
			MessageBox::Show("Введите элемент для добавления.", "Ошибка");
		}
		else
		{
			double value;
			if (!Double::TryParse(textBox_insert->Text, value))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				textBox_insert->Text = "";
				return;
			}
			if (textBox_insert->Text->Length > 5)
			{
				MessageBox::Show("Максимум 5 символов.", "Ошибка");
				textBox_insert->Text = "";
				return;
			}
			tree->insert(value);
			draw_tree_normal(tree);

			textBox_insert->Text = "";
			textBox_traversal->Text = "";
		}
	}

	// кнопка удаления элемента
	private: System::Void btn_erase_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox_erase->Text->Length == 0)
		{
			MessageBox::Show("Введите элемент для удаления.", "Ошибка");
		}
		else
		{
			double value;
			if (!Double::TryParse(textBox_erase->Text, value))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				textBox_erase->Text = "";
				return;
			}
			tree->erase(value);
			draw_tree_normal(tree);

			textBox_erase->Text = "";
			textBox_traversal->Text = "";
		}
	}

	// кнопка поиска элемента по значению
	private: System::Void btn_find_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox_find->Text->Length == 0)
		{
			MessageBox::Show("Введите элемент для поиска.", "Ошибка");
			draw_tree_normal(tree);
		}
		else
		{
			double value;
			if (!Double::TryParse(textBox_find->Text, value))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				draw_tree_normal(tree);
				textBox_find->Text = "";
				return;
			}

			Tree* found = tree->find(value);
			if (found == nullptr)
			{
				MessageBox::Show("Элемент не найден.", "Ошибка");
				draw_tree_normal(tree);
				textBox_find->Text = "";
				return;
			}
			draw_tree_search(tree, found);

			textBox_find->Text = "";
		}
	}

	// кнопка поиска минимального элемента
	private: System::Void btn_min_Click(System::Object^ sender, System::EventArgs^ e) {
		Tree* found = tree->root->minimum();
		if (found == nullptr)
		{
			MessageBox::Show("Элемент не найден.", "Ошибка");
			draw_tree_normal(tree);
			textBox_find->Text = "";
			return;
		}
		draw_tree_search(tree, found);
	}

	// кнопка прямого обхода
	private: System::Void btn_preorder_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ str = "";
		make_preorderString(tree->root, str);
		textBox_traversal->Text = str;

		draw_tree_normal(tree);
	}

	// кнопка симметричного обхода
	private: System::Void btn_inorder_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ str = "";
		make_inorderString(tree->root, str);
		textBox_traversal->Text = str;

		draw_tree_normal(tree);
	}

	// кнопка обратного обхода
	private: System::Void btn_postorder_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ str = "";
		make_postorderString(tree->root, str);
		textBox_traversal->Text = str;

		draw_tree_normal(tree);
	}

	// кнопка балансировки дерева
	private: System::Void btn_balance_Click(System::Object^ sender, System::EventArgs^ e) {
		tree->balance();
		draw_tree_normal(tree);
		textBox_traversal->Text = "";
	}

	// кнопка удаления дерева
	private: System::Void btn_clear_Click(System::Object^ sender, System::EventArgs^ e) {
		tree->clear();
		tree->root = nullptr;

		panel_to_draw->Controls->Clear();
		panel_to_draw->Refresh();

		textBox_insert->Text = "";
		textBox_erase->Text = "";
		textBox_find->Text = "";
		textBox_traversal->Text = "";
	}
};
}
