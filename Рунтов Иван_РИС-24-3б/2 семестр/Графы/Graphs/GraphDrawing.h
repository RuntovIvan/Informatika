#pragma once
#include "Graph.h"
//#include <cmath>
//#include <iostream>

namespace Graphs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для GraphDrawing
	/// </summary>
	public ref class GraphDrawing : public System::Windows::Forms::Form
	{
	public:
		GraphDrawing(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			DoubleBuffered = true;
			SetStyle(ControlStyles::OptimizedDoubleBuffer, true);
			SetStyle(ControlStyles::DoubleBuffer, true);
			SetStyle(ControlStyles::UserPaint, true);
			SetStyle(ControlStyles::AllPaintingInWmPaint, true);
			UpdateStyles();

			graph = new Graph();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~GraphDrawing()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel_to_draw;
	private: System::Windows::Forms::Button^ btn_add_vert;
	private: System::Windows::Forms::Button^ btn_del_vert;



	private: System::Windows::Forms::Button^ btn_DFS;
	private: System::Windows::Forms::Button^ btn_BFS;
	private: System::Windows::Forms::Button^ btn_Dijkstra;
	private: System::Windows::Forms::Button^ btn_Floyd;
	private: System::Windows::Forms::TextBox^ txt_DFS;
	private: System::Windows::Forms::Label^ lbl_DFS;
	private: System::Windows::Forms::Label^ lbl_BFS;
	private: System::Windows::Forms::TextBox^ txt_BFS;
	private: System::Windows::Forms::Label^ lbl_Dijkstra;
	private: System::Windows::Forms::TextBox^ txt_Dijkstra;
	private: System::Windows::Forms::Label^ lbl_Floyd_start;
	private: System::Windows::Forms::TextBox^ txt_Floyd_start;
	private: System::Windows::Forms::Label^ lbl_Floyd_end;
	private: System::Windows::Forms::TextBox^ txt_Floyd_end;
	private: System::Windows::Forms::Button^ btn_add_edge;
	private: System::Windows::Forms::Button^ btn_del_edge;
	private: System::Windows::Forms::Button^ btn_change_weight;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_add_vert;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_del_vert;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txt_add_edge_end;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_add_edge_start;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txt_del_edge_end;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txt_del_edge_start;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txt_change_weight_end;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txt_change_weight_start;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txt_add_edge_weight;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_change_weight_weight;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ btn_adj_matr;
	private: System::Windows::Forms::Button^ btn_shrt_paths_matr;
	private: System::Windows::Forms::Button^ btn_second_matr;




	public:
		Graph* graph;
		int rad = 30;
		Point dragStartPoint;
		int ind_drag_vert = -1;

	protected:


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GraphDrawing::typeid));
			this->panel_to_draw = (gcnew System::Windows::Forms::Panel());
			this->btn_add_vert = (gcnew System::Windows::Forms::Button());
			this->btn_del_vert = (gcnew System::Windows::Forms::Button());
			this->btn_DFS = (gcnew System::Windows::Forms::Button());
			this->btn_BFS = (gcnew System::Windows::Forms::Button());
			this->btn_Dijkstra = (gcnew System::Windows::Forms::Button());
			this->btn_Floyd = (gcnew System::Windows::Forms::Button());
			this->txt_DFS = (gcnew System::Windows::Forms::TextBox());
			this->lbl_DFS = (gcnew System::Windows::Forms::Label());
			this->lbl_BFS = (gcnew System::Windows::Forms::Label());
			this->txt_BFS = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Dijkstra = (gcnew System::Windows::Forms::Label());
			this->txt_Dijkstra = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Floyd_start = (gcnew System::Windows::Forms::Label());
			this->txt_Floyd_start = (gcnew System::Windows::Forms::TextBox());
			this->lbl_Floyd_end = (gcnew System::Windows::Forms::Label());
			this->txt_Floyd_end = (gcnew System::Windows::Forms::TextBox());
			this->btn_add_edge = (gcnew System::Windows::Forms::Button());
			this->btn_del_edge = (gcnew System::Windows::Forms::Button());
			this->btn_change_weight = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_add_vert = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_del_vert = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_add_edge_end = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_add_edge_start = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txt_del_edge_end = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_del_edge_start = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txt_change_weight_end = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txt_change_weight_start = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txt_add_edge_weight = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_change_weight_weight = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->btn_adj_matr = (gcnew System::Windows::Forms::Button());
			this->btn_shrt_paths_matr = (gcnew System::Windows::Forms::Button());
			this->btn_second_matr = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// panel_to_draw
			// 
			this->panel_to_draw->BackColor = System::Drawing::Color::White;
			this->panel_to_draw->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_to_draw->Location = System::Drawing::Point(570, 10);
			this->panel_to_draw->Name = L"panel_to_draw";
			this->panel_to_draw->Size = System::Drawing::Size(800, 600);
			this->panel_to_draw->TabIndex = 0;
			this->panel_to_draw->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GraphDrawing::panel_to_draw_Paint);
			this->panel_to_draw->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphDrawing::panel_to_draw_MouseDown);
			this->panel_to_draw->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphDrawing::panel_to_draw_MouseMove);
			this->panel_to_draw->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &GraphDrawing::panel_to_draw_MouseUp);
			// 
			// btn_add_vert
			// 
			this->btn_add_vert->Location = System::Drawing::Point(85, 75);
			this->btn_add_vert->Name = L"btn_add_vert";
			this->btn_add_vert->Size = System::Drawing::Size(150, 35);
			this->btn_add_vert->TabIndex = 1;
			this->btn_add_vert->Text = L"Добавить вершину";
			this->btn_add_vert->UseVisualStyleBackColor = true;
			this->btn_add_vert->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_add_vert_Click);
			// 
			// btn_del_vert
			// 
			this->btn_del_vert->Location = System::Drawing::Point(335, 75);
			this->btn_del_vert->Name = L"btn_del_vert";
			this->btn_del_vert->Size = System::Drawing::Size(150, 35);
			this->btn_del_vert->TabIndex = 2;
			this->btn_del_vert->Text = L"Удалить вершину";
			this->btn_del_vert->UseVisualStyleBackColor = true;
			this->btn_del_vert->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_del_vert_Click);
			// 
			// btn_DFS
			// 
			this->btn_DFS->Location = System::Drawing::Point(575, 645);
			this->btn_DFS->Name = L"btn_DFS";
			this->btn_DFS->Size = System::Drawing::Size(160, 30);
			this->btn_DFS->TabIndex = 3;
			this->btn_DFS->Text = L"Обход в глубину";
			this->btn_DFS->UseVisualStyleBackColor = true;
			this->btn_DFS->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_DFS_Click);
			// 
			// btn_BFS
			// 
			this->btn_BFS->Location = System::Drawing::Point(785, 645);
			this->btn_BFS->Name = L"btn_BFS";
			this->btn_BFS->Size = System::Drawing::Size(160, 30);
			this->btn_BFS->TabIndex = 4;
			this->btn_BFS->Text = L"Обход в ширину";
			this->btn_BFS->UseVisualStyleBackColor = true;
			this->btn_BFS->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_BFS_Click);
			// 
			// btn_Dijkstra
			// 
			this->btn_Dijkstra->Location = System::Drawing::Point(995, 645);
			this->btn_Dijkstra->Name = L"btn_Dijkstra";
			this->btn_Dijkstra->Size = System::Drawing::Size(160, 30);
			this->btn_Dijkstra->TabIndex = 5;
			this->btn_Dijkstra->Text = L"Алгоритм Дейкстры";
			this->btn_Dijkstra->UseVisualStyleBackColor = true;
			this->btn_Dijkstra->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_Dijkstra_Click);
			// 
			// btn_Floyd
			// 
			this->btn_Floyd->Location = System::Drawing::Point(1205, 645);
			this->btn_Floyd->Name = L"btn_Floyd";
			this->btn_Floyd->Size = System::Drawing::Size(160, 30);
			this->btn_Floyd->TabIndex = 6;
			this->btn_Floyd->Text = L"Алгоритм Флойда";
			this->btn_Floyd->UseVisualStyleBackColor = true;
			this->btn_Floyd->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_Floyd_Click);
			// 
			// txt_DFS
			// 
			this->txt_DFS->Location = System::Drawing::Point(575, 713);
			this->txt_DFS->Name = L"txt_DFS";
			this->txt_DFS->Size = System::Drawing::Size(160, 24);
			this->txt_DFS->TabIndex = 7;
			// 
			// lbl_DFS
			// 
			this->lbl_DFS->Location = System::Drawing::Point(575, 692);
			this->lbl_DFS->Name = L"lbl_DFS";
			this->lbl_DFS->Size = System::Drawing::Size(160, 18);
			this->lbl_DFS->TabIndex = 8;
			this->lbl_DFS->Text = L"Начальная вершина";
			this->lbl_DFS->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_BFS
			// 
			this->lbl_BFS->Location = System::Drawing::Point(785, 692);
			this->lbl_BFS->Name = L"lbl_BFS";
			this->lbl_BFS->Size = System::Drawing::Size(160, 18);
			this->lbl_BFS->TabIndex = 10;
			this->lbl_BFS->Text = L"Начальная вершина";
			this->lbl_BFS->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_BFS
			// 
			this->txt_BFS->Location = System::Drawing::Point(785, 713);
			this->txt_BFS->Name = L"txt_BFS";
			this->txt_BFS->Size = System::Drawing::Size(160, 24);
			this->txt_BFS->TabIndex = 9;
			// 
			// lbl_Dijkstra
			// 
			this->lbl_Dijkstra->Location = System::Drawing::Point(995, 692);
			this->lbl_Dijkstra->Name = L"lbl_Dijkstra";
			this->lbl_Dijkstra->Size = System::Drawing::Size(160, 18);
			this->lbl_Dijkstra->TabIndex = 12;
			this->lbl_Dijkstra->Text = L"Начальная вершина";
			this->lbl_Dijkstra->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_Dijkstra
			// 
			this->txt_Dijkstra->Location = System::Drawing::Point(995, 713);
			this->txt_Dijkstra->Name = L"txt_Dijkstra";
			this->txt_Dijkstra->Size = System::Drawing::Size(160, 24);
			this->txt_Dijkstra->TabIndex = 11;
			// 
			// lbl_Floyd_start
			// 
			this->lbl_Floyd_start->Location = System::Drawing::Point(1205, 692);
			this->lbl_Floyd_start->Name = L"lbl_Floyd_start";
			this->lbl_Floyd_start->Size = System::Drawing::Size(160, 18);
			this->lbl_Floyd_start->TabIndex = 14;
			this->lbl_Floyd_start->Text = L"Начальная вершина";
			this->lbl_Floyd_start->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_Floyd_start
			// 
			this->txt_Floyd_start->Location = System::Drawing::Point(1205, 713);
			this->txt_Floyd_start->Name = L"txt_Floyd_start";
			this->txt_Floyd_start->Size = System::Drawing::Size(160, 24);
			this->txt_Floyd_start->TabIndex = 13;
			// 
			// lbl_Floyd_end
			// 
			this->lbl_Floyd_end->Location = System::Drawing::Point(1205, 762);
			this->lbl_Floyd_end->Name = L"lbl_Floyd_end";
			this->lbl_Floyd_end->Size = System::Drawing::Size(160, 18);
			this->lbl_Floyd_end->TabIndex = 16;
			this->lbl_Floyd_end->Text = L"Конечная вершина";
			this->lbl_Floyd_end->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_Floyd_end
			// 
			this->txt_Floyd_end->Location = System::Drawing::Point(1205, 783);
			this->txt_Floyd_end->Name = L"txt_Floyd_end";
			this->txt_Floyd_end->Size = System::Drawing::Size(160, 24);
			this->txt_Floyd_end->TabIndex = 15;
			// 
			// btn_add_edge
			// 
			this->btn_add_edge->Location = System::Drawing::Point(15, 300);
			this->btn_add_edge->Name = L"btn_add_edge";
			this->btn_add_edge->Size = System::Drawing::Size(150, 35);
			this->btn_add_edge->TabIndex = 17;
			this->btn_add_edge->Text = L"Добавить ребро";
			this->btn_add_edge->UseVisualStyleBackColor = true;
			this->btn_add_edge->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_add_edge_Click);
			// 
			// btn_del_edge
			// 
			this->btn_del_edge->Location = System::Drawing::Point(210, 300);
			this->btn_del_edge->Name = L"btn_del_edge";
			this->btn_del_edge->Size = System::Drawing::Size(150, 35);
			this->btn_del_edge->TabIndex = 18;
			this->btn_del_edge->Text = L"Удалить ребро";
			this->btn_del_edge->UseVisualStyleBackColor = true;
			this->btn_del_edge->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_del_edge_Click);
			// 
			// btn_change_weight
			// 
			this->btn_change_weight->Location = System::Drawing::Point(405, 300);
			this->btn_change_weight->Name = L"btn_change_weight";
			this->btn_change_weight->Size = System::Drawing::Size(150, 35);
			this->btn_change_weight->TabIndex = 19;
			this->btn_change_weight->Text = L"Изменить вес";
			this->btn_change_weight->UseVisualStyleBackColor = true;
			this->btn_change_weight->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_change_weight_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(85, 134);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 18);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Значение";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_add_vert
			// 
			this->txt_add_vert->Location = System::Drawing::Point(85, 155);
			this->txt_add_vert->Name = L"txt_add_vert";
			this->txt_add_vert->Size = System::Drawing::Size(150, 24);
			this->txt_add_vert->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(335, 134);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 18);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Значение";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_del_vert
			// 
			this->txt_del_vert->Location = System::Drawing::Point(335, 155);
			this->txt_del_vert->Name = L"txt_del_vert";
			this->txt_del_vert->Size = System::Drawing::Size(150, 24);
			this->txt_del_vert->TabIndex = 22;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(15, 421);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 18);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Конечная вершина";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_add_edge_end
			// 
			this->txt_add_edge_end->Location = System::Drawing::Point(15, 442);
			this->txt_add_edge_end->Name = L"txt_add_edge_end";
			this->txt_add_edge_end->Size = System::Drawing::Size(150, 24);
			this->txt_add_edge_end->TabIndex = 26;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(15, 354);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 18);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Начальная вершина";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_add_edge_start
			// 
			this->txt_add_edge_start->Location = System::Drawing::Point(15, 375);
			this->txt_add_edge_start->Name = L"txt_add_edge_start";
			this->txt_add_edge_start->Size = System::Drawing::Size(150, 24);
			this->txt_add_edge_start->TabIndex = 24;
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(210, 421);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(150, 18);
			this->label5->TabIndex = 31;
			this->label5->Text = L"Конечная вершина";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_del_edge_end
			// 
			this->txt_del_edge_end->Location = System::Drawing::Point(210, 442);
			this->txt_del_edge_end->Name = L"txt_del_edge_end";
			this->txt_del_edge_end->Size = System::Drawing::Size(150, 24);
			this->txt_del_edge_end->TabIndex = 30;
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(210, 354);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(150, 18);
			this->label6->TabIndex = 29;
			this->label6->Text = L"Начальная вершина";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_del_edge_start
			// 
			this->txt_del_edge_start->Location = System::Drawing::Point(210, 375);
			this->txt_del_edge_start->Name = L"txt_del_edge_start";
			this->txt_del_edge_start->Size = System::Drawing::Size(150, 24);
			this->txt_del_edge_start->TabIndex = 28;
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(405, 421);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(150, 18);
			this->label7->TabIndex = 35;
			this->label7->Text = L"Конечная вершина";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_change_weight_end
			// 
			this->txt_change_weight_end->Location = System::Drawing::Point(405, 442);
			this->txt_change_weight_end->Name = L"txt_change_weight_end";
			this->txt_change_weight_end->Size = System::Drawing::Size(150, 24);
			this->txt_change_weight_end->TabIndex = 34;
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(405, 354);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(150, 18);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Начальная вершина";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_change_weight_start
			// 
			this->txt_change_weight_start->Location = System::Drawing::Point(405, 375);
			this->txt_change_weight_start->Name = L"txt_change_weight_start";
			this->txt_change_weight_start->Size = System::Drawing::Size(150, 24);
			this->txt_change_weight_start->TabIndex = 32;
			// 
			// label9
			// 
			this->label9->Location = System::Drawing::Point(15, 480);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(150, 18);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Вес";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_add_edge_weight
			// 
			this->txt_add_edge_weight->Location = System::Drawing::Point(15, 501);
			this->txt_add_edge_weight->Name = L"txt_add_edge_weight";
			this->txt_add_edge_weight->Size = System::Drawing::Size(150, 24);
			this->txt_add_edge_weight->TabIndex = 36;
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(405, 480);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(150, 18);
			this->label10->TabIndex = 39;
			this->label10->Text = L"Новый вес";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txt_change_weight_weight
			// 
			this->txt_change_weight_weight->Location = System::Drawing::Point(405, 501);
			this->txt_change_weight_weight->Name = L"txt_change_weight_weight";
			this->txt_change_weight_weight->Size = System::Drawing::Size(150, 24);
			this->txt_change_weight_weight->TabIndex = 38;
			// 
			// label11
			// 
			this->label11->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label11->Location = System::Drawing::Point(15, 28);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(540, 26);
			this->label11->TabIndex = 40;
			this->label11->Text = L"Вершины";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label12
			// 
			this->label12->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label12->Location = System::Drawing::Point(15, 245);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(540, 26);
			this->label12->TabIndex = 41;
			this->label12->Text = L"Ребра";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label13
			// 
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label13->Location = System::Drawing::Point(15, 584);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(540, 26);
			this->label13->TabIndex = 42;
			this->label13->Text = L"Матрицы";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_adj_matr
			// 
			this->btn_adj_matr->Location = System::Drawing::Point(85, 630);
			this->btn_adj_matr->Name = L"btn_adj_matr";
			this->btn_adj_matr->Size = System::Drawing::Size(400, 30);
			this->btn_adj_matr->TabIndex = 43;
			this->btn_adj_matr->Text = L"Матрица смежности";
			this->btn_adj_matr->UseVisualStyleBackColor = true;
			this->btn_adj_matr->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_adj_matr_Click);
			// 
			// btn_shrt_paths_matr
			// 
			this->btn_shrt_paths_matr->Location = System::Drawing::Point(85, 670);
			this->btn_shrt_paths_matr->Name = L"btn_shrt_paths_matr";
			this->btn_shrt_paths_matr->Size = System::Drawing::Size(400, 30);
			this->btn_shrt_paths_matr->TabIndex = 44;
			this->btn_shrt_paths_matr->Text = L"Матрица длин путей";
			this->btn_shrt_paths_matr->UseVisualStyleBackColor = true;
			this->btn_shrt_paths_matr->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_shrt_paths_matr_Click);
			// 
			// btn_second_matr
			// 
			this->btn_second_matr->Location = System::Drawing::Point(85, 710);
			this->btn_second_matr->Name = L"btn_second_matr";
			this->btn_second_matr->Size = System::Drawing::Size(400, 30);
			this->btn_second_matr->TabIndex = 45;
			this->btn_second_matr->Text = L"Матрица построения путей";
			this->btn_second_matr->UseVisualStyleBackColor = true;
			this->btn_second_matr->Click += gcnew System::EventHandler(this, &GraphDrawing::btn_second_matr_Click);
			// 
			// GraphDrawing
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1382, 853);
			this->Controls->Add(this->btn_second_matr);
			this->Controls->Add(this->btn_shrt_paths_matr);
			this->Controls->Add(this->btn_adj_matr);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->txt_change_weight_weight);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txt_add_edge_weight);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->txt_change_weight_end);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->txt_change_weight_start);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txt_del_edge_end);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txt_del_edge_start);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txt_add_edge_end);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txt_add_edge_start);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txt_del_vert);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txt_add_vert);
			this->Controls->Add(this->btn_change_weight);
			this->Controls->Add(this->btn_del_edge);
			this->Controls->Add(this->btn_add_edge);
			this->Controls->Add(this->lbl_Floyd_end);
			this->Controls->Add(this->txt_Floyd_end);
			this->Controls->Add(this->lbl_Floyd_start);
			this->Controls->Add(this->txt_Floyd_start);
			this->Controls->Add(this->lbl_Dijkstra);
			this->Controls->Add(this->txt_Dijkstra);
			this->Controls->Add(this->lbl_BFS);
			this->Controls->Add(this->txt_BFS);
			this->Controls->Add(this->lbl_DFS);
			this->Controls->Add(this->txt_DFS);
			this->Controls->Add(this->btn_Floyd);
			this->Controls->Add(this->btn_Dijkstra);
			this->Controls->Add(this->btn_BFS);
			this->Controls->Add(this->btn_DFS);
			this->Controls->Add(this->btn_del_vert);
			this->Controls->Add(this->btn_add_vert);
			this->Controls->Add(this->panel_to_draw);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GraphDrawing";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GraphDrawing";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
// вершины
	private: System::Void btn_add_vert_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txt_add_vert->Text->Length == 0)
		{
			MessageBox::Show("Введите вершину для добавления.", "Ошибка");
		}
		else
		{
			int vertex;
			if (!Int32::TryParse(txt_add_vert->Text, vertex))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_add_vert->Text = "";
				return;
			}

			if (graph->IsFull())
			{
				MessageBox::Show("Достигнуто максимальное количество вершин.", "Ошибка");
				txt_add_vert->Text = "";
				return;
			}

			graph->AddVertex(vertex);
			txt_add_vert->Text = "";

			panel_to_draw->Invalidate();
		}
	}

	private: System::Void btn_del_vert_Click(System::Object^ sender, System::EventArgs^ e) {
		if (txt_del_vert->Text->Length == 0)
		{
			MessageBox::Show("Введите вершину для удаления.", "Ошибка");
		}
		else
		{
			int vertex;
			if (!Int32::TryParse(txt_del_vert->Text, vertex))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_del_vert->Text = "";
				return;
			}

			if (graph->IsEmpty())
			{
				MessageBox::Show("Граф пустой.", "Ошибка");
				txt_del_vert->Text = "";
				return;
			}

			graph->DelVert(vertex);
			txt_del_vert->Text = "";

			panel_to_draw->Invalidate();
		}
	}


//ребра
	private: System::Void btn_add_edge_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text_start = txt_add_edge_start->Text;
		String^ text_end = txt_add_edge_end->Text;
		String^ text_weight = txt_add_edge_weight->Text;

		if (text_start->Length == 0 || text_end->Length == 0 || text_weight->Length == 0)
		{
			MessageBox::Show("Какое-то значение пропущено.", "Ошибка");
		}
		else
		{
			int start_vert, end_vert, weight;
			if (!Int32::TryParse(text_start, start_vert) || !Int32::TryParse(text_end, end_vert) || !Int32::TryParse(text_weight, weight))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_add_edge_start->Text = "";
				txt_add_edge_end->Text = "";
				txt_add_edge_weight->Text = "";
				return;
			}

			if (graph->GetVertPos(start_vert) == -1 || graph->GetVertPos(end_vert) == -1)
			{
				MessageBox::Show("Какой-то (или обеих) вершин нет в графе.", "Ошибка");
				txt_add_edge_start->Text = "";
				txt_add_edge_end->Text = "";
				txt_add_edge_weight->Text = "";
				return;
			}

			if (start_vert == end_vert)
			{
				MessageBox::Show("Введена одна и та же вершина.", "Ошибка");
				txt_add_edge_start->Text = "";
				txt_add_edge_end->Text = "";
				txt_add_edge_weight->Text = "";
				return;
			}

			graph->AddEdge(start_vert, end_vert, weight);
			graph->Fl_AddEdge(start_vert, end_vert, weight);

			txt_add_edge_start->Text = "";
			txt_add_edge_end->Text = "";
			txt_add_edge_weight->Text = "";

			panel_to_draw->Invalidate();
		}
	}

	private: System::Void btn_del_edge_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt_start_vert = txt_del_edge_start->Text;
		String^ txt_end_vert = txt_del_edge_end->Text;

		if (txt_start_vert->Length == 0 || txt_end_vert->Length == 0)
		{
			MessageBox::Show("Какое-то значение пропущено.", "Ошибка");
		}
		else
		{
			int start_vert, end_vert;
			if (!Int32::TryParse(txt_start_vert, start_vert) || !Int32::TryParse(txt_end_vert, end_vert))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_del_edge_start->Text = "";
				txt_del_edge_end->Text = "";
				return;
			}

			if (graph->GetVertPos(start_vert) == -1 || graph->GetVertPos(end_vert) == -1)
			{
				MessageBox::Show("Какой-то (или обеих) вершин нет в графе.", "Ошибка");
				txt_del_edge_start->Text = "";
				txt_del_edge_end->Text = "";
				return;
			}

			if (start_vert == end_vert)
			{
				MessageBox::Show("Введена одна и та же вершина.", "Ошибка");
				txt_del_edge_start->Text = "";
				txt_del_edge_end->Text = "";
				return;
			}

			graph->DelEdge(start_vert, end_vert);
			graph->Fl_DelEdge(start_vert, end_vert);
			txt_del_edge_start->Text = "";
			txt_del_edge_end->Text = "";

			panel_to_draw->Invalidate();
		}
	}

	private: System::Void btn_change_weight_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt_start_vert = txt_change_weight_start->Text;
		String^ txt_end_vert = txt_change_weight_end->Text;
		String^ txt_weight = txt_change_weight_weight->Text;

		if (txt_start_vert->Length == 0 || txt_end_vert->Length == 0 || txt_weight->Length == 0)
		{
			MessageBox::Show("Какое-то значение пропущено.", "Ошибка");
		}
		else
		{
			int start_vert, end_vert, new_weight;
			if (!Int32::TryParse(txt_start_vert, start_vert) || !Int32::TryParse(txt_end_vert, end_vert) || !Int32::TryParse(txt_weight, new_weight))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_change_weight_start->Text = "";
				txt_change_weight_end->Text = "";
				txt_change_weight_weight->Text = "";
				return;
			}

			if (graph->GetVertPos(start_vert) == -1 || graph->GetVertPos(end_vert) == -1)
			{
				MessageBox::Show("Какой-то (или обеих) вершин нет в графе.", "Ошибка");
				txt_change_weight_start->Text = "";
				txt_change_weight_end->Text = "";
				txt_change_weight_weight->Text = "";
				return;
			}

			if (start_vert == end_vert)
			{
				MessageBox::Show("Введена одна и та же вершина.", "Ошибка");
				txt_change_weight_start->Text = "";
				txt_change_weight_end->Text = "";
				txt_change_weight_weight->Text = "";
				return;
			}

			graph->ChangeEdgeWeight(start_vert, end_vert, new_weight);
			graph->Fl_ChangeEdgeWeight(start_vert, end_vert, new_weight);
			txt_change_weight_start->Text = "";
			txt_change_weight_end->Text = "";
			txt_change_weight_weight->Text = "";

			panel_to_draw->Invalidate();
		}
	}

// матрицы
	// формирование матрицы смежности
	private: System::Void print_adjMatrix(String^& str)
	{
		if (!graph->IsEmpty())
		{
			str += "-\t";
			for (int i = 0; i < graph->vertList.size(); i++)
				str = str + System::Convert::ToString(graph->vertList[i]) + "\t";
			
			str += "\n";

			for (int i = 0; i < graph->vertList.size(); i++)
			{
				str += System::Convert::ToString(graph->vertList[i]) + "\t";
				for (int j = 0; j < graph->vertList.size(); j++)
					str = str + System::Convert::ToString(graph->adjMatrix[i][j]) + "\t";
				str += "\n";
			}
		}
		else
		{
			str = "Граф пустой";
		}
	}
	
	// формирование матрицы путей
	private: System::Void print_shortestPathsMatrix(String^& str)
	{
		graph->Floyd();
		if (!graph->IsEmpty())
		{
			str += "-\t";
			for (int i = 0; i < graph->vertList.size(); i++)
				str = str + System::Convert::ToString(graph->vertList[i]) + "\t";

			str += "\n";

			for (int i = 0; i < graph->vertList.size(); i++)
			{
				str += System::Convert::ToString(graph->vertList[i]) + "\t";
				for (int j = 0; j < graph->vertList.size(); j++)
					if (graph->shortestPathsMatrix[i][j] != inf)
						str = str + System::Convert::ToString(graph->shortestPathsMatrix[i][j]) + "\t";
					else
						str = str + "inf" + "\t";
				str += "\n";
			}
		}
		else
		{
			str = "Граф пустой";
		}
	}

	// формирование матрицы построения путей
	private: System::Void print_secondMatrix(String^& str)
	{
		graph->Floyd();
		if (!graph->IsEmpty())
		{
			str += "-\t";
			for (int i = 0; i < graph->vertList.size(); i++)
				str = str + System::Convert::ToString(graph->vertList[i]) + "\t";

			str += "\n";

			for (int i = 0; i < graph->vertList.size(); i++)
			{
				str += System::Convert::ToString(graph->vertList[i]) + "\t";
				for (int j = 0; j < graph->vertList.size(); j++)
					str = str + System::Convert::ToString(graph->secondMatrix[i][j]) + "\t";
				str += "\n";
			}
		}
		else
		{
			str = "Граф пустой";
		}
	}

	private: System::Void btn_adj_matr_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ message;
		print_adjMatrix(message);
		MessageBox::Show(message, "Матрица смежности");
	}
	private: System::Void btn_shrt_paths_matr_Click(System::Object^ sender, System::EventArgs^ e) {
		graph->Floyd();
		String^ message;
		print_shortestPathsMatrix(message);
		MessageBox::Show(message, "Матрица длин путей");
	}
	private: System::Void btn_second_matr_Click(System::Object^ sender, System::EventArgs^ e) {
		graph->Floyd();
		String^ message;
		print_secondMatrix(message);
		MessageBox::Show(message, "Матрица построения путей");
	}


// алгоритмы
	// формирование ответа для обхода в глубину
	private: System::Void print_routeDFS(String^& str, std::vector<int> route)
	{
		str += System::Convert::ToString(route[0]) + " -> ";
		for (int i = 1; i < route.size() - 1; i++)
			str += System::Convert::ToString(route[i]) + " -> ";
		str += System::Convert::ToString(route[route.size() - 1]);
	}

	// формирование ответа для обхода в ширину
	private: System::Void print_routeBFS(String^& str, std::vector<int> route)
	{
		str += System::Convert::ToString(route[0]) + " -> ";
		for (int i = 1; i < route.size() - 1; i++)
			str += System::Convert::ToString(route[i]) + " -> ";
		str += System::Convert::ToString(route[route.size() - 1]);
	}

	// формирование ответа для алгоритма Дейкстры
	private: System::Void print_resDijkstra(String^& str, std::vector<int> result)
	{
		for (int i = 0; i < result.size(); i++)
			if (result[i] != inf)
				str += System::Convert::ToString(graph->vertList[i]) + " - " + System::Convert::ToString(result[i]) + "\t";
			else
				str += System::Convert::ToString(graph->vertList[i]) + " - " + "inf" + "\t";
	}

	// формирование ответа для алгоритма Флойда
	private: System::Void print_resFloyd(String^& str, int start_vert, int end_vert)
	{
		str += "Кратчайший путь от вершины " + System::Convert::ToString(start_vert) + " до вершины " + System::Convert::ToString(end_vert) + "\n";

		int start_pos = graph->GetVertPos(start_vert), end_pos = graph->GetVertPos(end_vert);
		if (graph->secondMatrix[start_pos][end_pos] != 0)
		{
			str += System::Convert::ToString(start_vert) + "\t";
			int cur = graph->secondMatrix[start_pos][end_pos];

			while (cur != 0)
			{
				str += System::Convert::ToString(cur) + "\t";

				if (graph->secondMatrix[graph->GetVertPos(cur)][end_pos] != 0)
				{
					cur = graph->secondMatrix[graph->GetVertPos(cur)][end_pos];
				}
				else
					cur = 0;
			}
			str += "\nВес пути: " + System::Convert::ToString(graph->shortestPathsMatrix[start_pos][end_pos]);
		}
		else
		{
			str += "Между вершинами нет пути.";
		}
	}

	

	private: System::Void btn_DFS_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text_start = txt_DFS->Text;

		if (text_start->Length == 0)
		{
			MessageBox::Show("Введите начальную вершину для DFS.", "Ошибка");
		}
		else
		{
			int start_vert;
			if (!Int32::TryParse(text_start, start_vert))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_DFS->Text = "";
				return;
			}

			String^ message;
			if (graph->GetVertPos(start_vert) == -1)
			{
				MessageBox::Show("Вершины в графе нет.", "Ошибка");
				txt_DFS->Text = "";
				return;
			}
			else if (graph->GetNeighbours(start_vert).size() == 0)
			{
				MessageBox::Show("У вершины нет соседей.", "Ошибка");
				txt_DFS->Text = "";
				return;
			}
			else
			{
				std::vector<bool> visited;
				for (int i = 0; i < graph->vertList.size(); i++)
					visited.push_back(false);

				std::vector<int> route;
				graph->DFS(start_vert, visited, route);

				String^ message;
				print_routeDFS(message, route);

				MessageBox::Show(message, "DFS");
				txt_DFS->Text = "";
			}
		}
	}
	private: System::Void btn_BFS_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text_start = txt_BFS->Text;

		if (text_start->Length == 0)
		{
			MessageBox::Show("Введите начальную вершину для DFS.", "Ошибка");
		}
		else
		{
			int start_vert;
			if (!Int32::TryParse(text_start, start_vert))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_BFS->Text = "";
				return;
			}

			String^ message;
			if (graph->GetVertPos(start_vert) == -1)
			{
				MessageBox::Show("Вершины в графе нет.", "Ошибка");
				txt_BFS->Text = "";
				return;
			}
			else if (graph->GetNeighbours(start_vert).size() == 0)
			{
				MessageBox::Show("У вершины нет соседей.", "Ошибка");
				txt_BFS->Text = "";
				return;
			}
			else
			{
				std::vector<bool> visited;
				for (int i = 0; i < graph->vertList.size(); i++)
					visited.push_back(false);

				std::vector<int> route;
				graph->BFS(start_vert, visited, route);

				String^ message;
				print_routeBFS(message, route);

				MessageBox::Show(message, "BFS");
				txt_BFS->Text = "";
			}
		}
	}
	private: System::Void btn_Dijkstra_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ text_start = txt_Dijkstra->Text;

		if (text_start->Length == 0)
		{
			MessageBox::Show("Введите начальную вершину для алгоритма Дейкстры.", "Ошибка");
		}
		else
		{
			int start_vert;
			if (!Int32::TryParse(text_start, start_vert))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_Dijkstra->Text = "";
				return;
			}

			String^ message;
			if (graph->GetVertPos(start_vert) == -1)
			{
				MessageBox::Show("Вершины в графе нет.", "Ошибка");
				txt_Dijkstra->Text = "";
				return;
			}
			
			else
			{
				std::vector<int> res;
				if (graph->Dijkstra(start_vert, res) != -1)
				{
					print_resDijkstra(message, res);
					MessageBox::Show(message, "Алгоритм Дейкстры");
					txt_Dijkstra->Text = "";
				}
				else
				{
					MessageBox::Show("В графе есть ребра с отрицательными весами.", "Ошибка");
					txt_Dijkstra->Text = "";
					return;
				}
			}
		}
	}

	private: System::Void btn_Floyd_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ txt_start_vert = txt_Floyd_start->Text;
		String^ txt_end_vert = txt_Floyd_end->Text;

		if (txt_start_vert->Length == 0 || txt_end_vert->Length == 0)
		{
			MessageBox::Show("Какое-то значение пропущено.", "Ошибка");
		}
		else
		{
			int start_vert, end_vert;
			if (!Int32::TryParse(txt_start_vert, start_vert) || !Int32::TryParse(txt_end_vert, end_vert))
			{
				MessageBox::Show("Ошибка преобразования.", "Ошибка");
				txt_Floyd_start->Text = "";
				txt_Floyd_end->Text = "";
				return;
			}

			if (graph->GetVertPos(start_vert) == -1 || graph->GetVertPos(end_vert) == -1)
			{
				MessageBox::Show("Какой-то (или обеих) вершин нет в графе.", "Ошибка");
				txt_Floyd_start->Text = "";
				txt_Floyd_end->Text = "";
				return;
			}

			graph->Floyd();
			String^ message;
			print_resFloyd(message, start_vert, end_vert);

			MessageBox::Show(message, "Алгоритм Флойда");
			txt_Floyd_start->Text = "";
			txt_Floyd_end->Text = "";
		}
	}


// отрисовка
	private: System::Void drawcircles()
	{
		Graphics^ g = panel_to_draw->CreateGraphics();
		Pen^ circle_pen = gcnew Pen(Color::Black, 5);
		SolidBrush^ circle_brush = gcnew SolidBrush(Color::White);
		SolidBrush^ text_brush = gcnew SolidBrush(Color::Black);
		
		// для отрисовки текста
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 16);

		for (int i = 0; i < graph->vertList.size(); i++)
		{
			int pos_x = graph->posList[i].x - rad;
			int pos_y = graph->posList[i].y - rad;
			g->FillEllipse(circle_brush, pos_x, pos_y, rad * 2, rad * 2);
			g->DrawEllipse(circle_pen, pos_x, pos_y, rad * 2, rad * 2);

			String^ str = System::Convert::ToString(graph->vertList[i]);
			SizeF^ text_size = g->MeasureString(str, font);
			float text_x = graph->posList[i].x - text_size->Width / 2;
			float text_y = graph->posList[i].y - text_size->Height / 2;
			g->DrawString(str, font, text_brush, text_x, text_y);

			delete str, text_size;
		}

		delete g, circle_pen, circle_brush, text_brush, font;
	}

	private: System::Void drawedges()
	{
		Graphics^ g = panel_to_draw->CreateGraphics();
		Pen^ edgepen = gcnew Pen(Color::Black);
		Drawing2D::AdjustableArrowCap^ arrowCap = gcnew Drawing2D::AdjustableArrowCap(5, 5);
		edgepen->CustomEndCap = arrowCap;

		for (int i = 0; i < graph->vertList.size(); i++)
			for (int j = 0; j < graph->vertList.size(); j++)
			{
				// отрисовка ребер
				if (graph->adjMatrix[i][j] != 0)
				{
					Pos start_vert_pos = graph->posList[i];
					Pos end_vert_pos = graph->posList[j];

					int vert_dx = end_vert_pos.x - start_vert_pos.x;
					int vert_dy = end_vert_pos.y - start_vert_pos.y;

					float len = sqrt(pow(vert_dx, 2) + pow(vert_dy, 2));

					float dx = (vert_dx * rad) / len;
					float dy = (vert_dy * rad) / len;

					g->DrawLine(edgepen, start_vert_pos.x, start_vert_pos.y, end_vert_pos.x - dx, end_vert_pos.y - dy);
				}
			}
		delete g, edgepen, arrowCap;
	}

	private: System::Void drawweights()
	{
		Graphics^ g = panel_to_draw->CreateGraphics();
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 20, FontStyle::Bold);
		SolidBrush^ text_brush = gcnew SolidBrush(Color::Red);

		for (int i = 0; i < graph->vertList.size(); i++)
			for (int j = 0; j < graph->vertList.size(); j++)
			{

				// отрисовка весов
				if (graph->adjMatrix[i][j] != 0)
				{
					Pos start_vert_pos = graph->posList[i];
					Pos end_vert_pos = graph->posList[j];

					int vert_dx = end_vert_pos.x - start_vert_pos.x;
					int vert_dy = end_vert_pos.y - start_vert_pos.y;

					float len = sqrt(pow(vert_dx, 2) + pow(vert_dy, 2));

					float dx = (vert_dx * rad * 3) / len;
					float dy = (vert_dy * rad * 3) / len;

					String^ str = System::Convert::ToString(graph->adjMatrix[i][j]);
					SizeF^ text_size = g->MeasureString(str, font);
					float text_x = graph->posList[j].x - dx - text_size->Width / 2;
					float text_y = graph->posList[j].y - dy - text_size->Height / 2;
					g->DrawString(str, font, text_brush, text_x, text_y);

					delete str, text_size;
				}
			}
		delete g, font, text_brush;
	}

	private: System::Void panel_to_draw_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		for (int i = 0; i < graph->posList.size(); i++)
		{
			int dx = e->X - graph->posList[i].x;
			int dy = e->Y - graph->posList[i].y;

			if (dx * dx + dy * dy <= rad * rad)
			{
				graph->posList[i].isDragging = true;
				dragStartPoint = e->Location;
				ind_drag_vert = i;
				return;
			}
		}
	}

	private: System::Void panel_to_draw_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (ind_drag_vert != -1 && graph->posList[ind_drag_vert].isDragging)
		{
			int dx = e->X - dragStartPoint.X;
			int dy = e->Y - dragStartPoint.Y;

			graph->posList[ind_drag_vert].x += dx;
			graph->posList[ind_drag_vert].y += dy;

			panel_to_draw->Invalidate();
			dragStartPoint = e->Location;
		}
	}
	private: System::Void panel_to_draw_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (ind_drag_vert != -1)
		{
			graph->posList[ind_drag_vert].isDragging = false;
			ind_drag_vert = -1;
		}
	}
	private: System::Void panel_to_draw_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;
		drawedges();
		drawweights();
		drawcircles();
	}
};
}
