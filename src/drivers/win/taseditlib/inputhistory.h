//Specification file for Input History class

#define UNDO_HINT_TIME 200

#define MODTYPE_INIT 0
#define MODTYPE_CHANGE 1
#define MODTYPE_SET 2
#define MODTYPE_UNSET 3
#define MODTYPE_INSERT 4
#define MODTYPE_DELETE 5
#define MODTYPE_TRUNCATE 6
#define MODTYPE_CLEAR 7
#define MODTYPE_CUT 8
#define MODTYPE_PASTE 9
#define MODTYPE_PASTEINSERT 10
#define MODTYPE_CLONE 11
#define MODTYPE_RECORD 12
#define MODTYPE_IMPORT 13
#define MODTYPE_BRANCH_0 14
#define MODTYPE_BRANCH_1 15
#define MODTYPE_BRANCH_2 16
#define MODTYPE_BRANCH_3 17
#define MODTYPE_BRANCH_4 18
#define MODTYPE_BRANCH_5 19
#define MODTYPE_BRANCH_6 20
#define MODTYPE_BRANCH_7 21
#define MODTYPE_BRANCH_8 22
#define MODTYPE_BRANCH_9 23

#define HISTORY_COHERENT_COLOR 0xF9DDE6
#define HISTORY_NORMAL_COLOR 0xFFFFFF

class INPUT_HISTORY
{
public:
	INPUT_HISTORY();
	void init(int new_size);
	void free();

	void update();		// called every frame

	void save(EMUFILE *os);
	void load(EMUFILE *is);

	int undo();
	int redo();
	int jump(int new_pos);

	void AddInputSnapshotToHistory(INPUT_SNAPSHOT &inp);

	int RegisterInputChanges(int mod_type, int start = 0, int end =-1);

	int InputChanged(int start, int end);
	int InputInserted(int start);
	int InputDeleted(int start);

	INPUT_SNAPSHOT& GetCurrentSnapshot();
	INPUT_SNAPSHOT& GetNextToCurrentSnapshot();
	char* GetItemDesc(int pos);
	bool GetItemCoherence(int pos);
	int GetUndoHint();

	void GetDispInfo(NMLVDISPINFO* nmlvDispInfo);
	LONG CustomDraw(NMLVCUSTOMDRAW* msg);
	void Click(LPNMITEMACTIVATE info);

	void RedrawHistoryList();
	void UpdateHistoryList();

private:
	std::vector<INPUT_SNAPSHOT> input_snapshots;

	int history_cursor_pos;
	int history_start_pos;
	int history_total_items;
	int history_size;

	int undo_hint_pos, old_undo_hint_pos;
	int undo_hint_time;
	bool old_show_undo_hint, show_undo_hint;

};

