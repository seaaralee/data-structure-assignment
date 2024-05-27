/*
    Mutia Rani Zahra Meilani
    2311102182

*/

#include <iostream>
using namespace std;

// DEKLARASI POHON
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};

// POINTER GLOBAL
Pohon *root;

// INIT
void init_182_ara()
{
    root = NULL;
}

// CEK POHON
bool isEmpty()
{
    return root == NULL;
}

// NODE POHON
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// FUNGSI BUAT NODE
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "⊹ • NODE '" << data << "' DIBUAT MENJADI ROOT • ⊹" << endl;
    }
    else
    {
        cout << "⊹ • SUDAH ADA POHON • ⊹" << endl;
    }
}

// FUNGSI INSERT KIRI
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "⊹ • NODE '" << node->data << "' SUDAH ADA DI CHILD KIRI • ⊹" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "⊹ • NODE '" << data << "' DITAMBAHKAN KE CHILD KIRI " << node->data << " • ⊹" << endl;
            return baru;
        }
    }
}

// FUNGSI INSERT KANAN
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "⊹ • NODE '" << node->data << "' SUDAH ADA DI CHILD KANAN • ⊹" << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "⊹ • NODE '" << data << "' DITAMBAHKAN KE CHILD KANAN " << node->data << " • ⊹" << endl;
            return baru;
        }
    }
}

// FUNGSI UPDATE NODE
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "⊹ • NODE '" << temp << "' DIUBAH MENJADI " << data << " • ⊹" << endl;
        }
    }
}

// FUNGSI RETRIEVE
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            cout << "⊹ • DATA NODE : " << node->data << endl;
        }
    }
}

// FUNGSI FIND NODE
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    }
    else
    {
        if (!node)
        {
            cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        }
        else
        {
            cout << "⊹ • DATA NODE : " << node->data << endl;
            cout << "↳ ROOT : " << root->data << endl;
            if (!node->parent)
                cout << "↳ PARENT : ✖" << endl;
            else
                cout << "↳ PARENT : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "↳ SIBLING : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "↳ SIBLING : " << node->parent->right->data << endl;
            else
                cout << "↳ SIBLING : ✖" << endl;
            if (!node->left)
                cout << "↳ CHILD KIRI : ✖" << endl;
            else
                cout << "↳ CHILD KIRI : " << node->left->data << endl;
            if (!node->right)
                cout << "↳ CHILD KANAN : ✖" << endl;
            else
                cout << "↳ CHILD KANAN : " << node->right->data << endl;
        }
    }
}

// FUNGSI SHOW CHILD
void showChildren(Pohon *node)
{
    if (node == NULL)
    {
        cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        cout << "⊹ • NODE '" << node->data << "' TIDAK PUNYA CHILD • ⊹" << endl;
        return;
    }
    cout << "⊹ • CHILD NODE " << node->data << " : ";
    if (node->left != NULL)
        cout << "\n↳ KIRI : " << node->left->data << " ";
    if (node->right != NULL)
        cout << "\n↳ KANAN : " << node->right->data << " ";
    cout << endl;
}

// FUNGSI SHOW DESCENDANT
void showDescendants(Pohon *node)
{
    if (node == NULL)
    {
        cout << "⊹ • NODE TIDAK ADA • ⊹" << endl;
        return;
    }
    cout << "\n⊹ • DESCENDANTS NODE " << node->data << " :";
    if (node->left != NULL)
    {
        cout << node->left->data << " ";
        showDescendants(node->left);
    }
    if (node->right != NULL)
    {
        cout << node->right->data << " ";
        showDescendants(node->right);
    }
    cout << endl;
}

// FUNGSI PREORDER
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// FUNGSI INORDER
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}

// FUNGSI POSTORDER
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}

// FUNGSI HAPUS NODE TREE
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}

// HAPUS TREE
void clear()
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        deleteTree(root);
        cout << "⊹ • POHON DIHAPUS • ⊹" << endl;
    }
}

// FUNGSI HAPUS SUBTREE
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "⊹ • NODE SUBTREE '" << node->data << "' DIHAPUS • ⊹" << endl;
    }
}

// CEK SIZE TREE
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// CEK HEIGHT
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "⊹ • BUAT POHON DULU • ⊹" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}

// FUNGSI KARAKTERISTIK
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "↳ SIZE : " << s << endl;
    cout << "↳ HEIGHT: " << h << endl;
    if (h != 0)
        cout << "↳ AVERAGE NODE : " << s / h << endl;
    else
        cout << "↳ AVERAGE NODE : 0" << endl;
}

// FIND NODE
Pohon *findNode(Pohon *node, char data)
{

    if (node == NULL)
        return NULL;

    if (node->data == data)
        return node;

    Pohon *leftResult = findNode(node->left, data);

    if (leftResult != NULL)
        return leftResult;

    return findNode(node->right, data);
}

// MENU
void menu()
{
    char choice, data, parentData;
    Pohon *node = NULL;
    do
    {
        cout << "\n˚₊‧꒰ა PROGRAM MEMBUAT TREE ໒꒱ ‧₊˚" << endl;
        cout << "ʚ 1 ɞ ⁺˖ BUAT ROOT ⸝⸝" << endl;
        cout << "ʚ 2 ɞ ⁺˖ TAMBAH NODE ⸝⸝" << endl;
        cout << "ʚ 3 ɞ ⁺˖ UBAH NODE ⸝⸝" << endl;
        cout << "ʚ 4 ɞ ⁺˖ SHOW NODE ( DATA, INFO, CHILD, DESCENDANT ) ⸝⸝" << endl;
        cout << "ʚ 5 ɞ ⁺˖ SHOW NODE TRANVERSAL ( PREORDER, INORDER, POSTORDER ) ⸝⸝" << endl;
        cout << "ʚ 6 ɞ ⁺˖ HAPUS SUBTREE ⸝⸝" << endl;
        cout << "ʚ 7 ɞ ⁺˖ HAPUS TREE ⸝⸝" << endl;
        cout << "ʚ 8 ɞ ⁺˖ KARAKTERISTIK TREE ⸝⸝" << endl;
        cout << "ʚ 0 ɞ ⁺˖ KELUAR ⸝⸝" << endl;
        cout << "✎ PILIH MENU : ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "\n˚₊‧꒰ BUAT ROOT ꒱ ‧₊˚" << endl;
            cout << "↳ INPUT DATA ROOT : ";
            cin >> data;
            buatNode(data);
            break;

        case '2':
            cout << "\n˚₊‧꒰ TAMBAH NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA PARENT : ";
            cin >> parentData;
            node = findNode(root, parentData);
            if (node != NULL)
            {
                int childChoice;
                cout << "\n˚₊‧꒰ PILIH LOKASI TAMBAH NODE ꒱ ‧₊˚" << endl;
                cout << "ʚ 1 NODE KIRI ⸝⸝" << endl;
                cout << "ʚ 2 NODE KANAN ⸝⸝" << endl;
                cout << "✎ PILIH LOKASI : ";
                cin >> childChoice;
                if (childChoice == 1)
                {
                    cout << "↳ MASUKAN DATA NODE KIRI :";
                    cin >> data;
                    insertLeft(data, node);
                }
                else if (childChoice == 2)
                {
                    cout << "↳ MASUKAN DATA NODE KANAN :";
                    cin >> data;
                    insertRight(data, node);
                }
                else
                {
                    cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
                }
            }
            break;

        case '3':
        cout << "\n˚₊‧꒰ UBAH NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA NODE YANG INGIN DIUBAH : ";
            cin >> data;
            node = findNode(root, data);
            if (node != NULL)
            {
                cout << "↳ MASUKAN DATA BARU : ";
                cin >> data;
                update(data, node);
            }
            break;

        case '4':
        cout << "\n˚₊‧꒰ SHOW NODE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN DATA NODE YANG INGIN DITAMPILKAN : ";
            cin >> data;
            node = findNode(root, data);
            if (node != NULL)
            {
                char infoChoice;
                cout << "\n˚₊‧꒰ PILIH TAMPILAN NODE ꒱ ‧₊˚" << endl;
                cout << "ʚ 1 DATA NODE ⸝⸝" << endl;
                cout << "ʚ 2 INFO NODE ⸝⸝" << endl;
                cout << "ʚ 3 NODE CHILD ⸝⸝" << endl;
                cout << "ʚ 4 NODE DESCENDANT ⸝⸝" << endl;
                cout << "✎ PILIH INFORMASI : " << endl;
                cin >> infoChoice;
                switch (infoChoice)
                {
                case '1':
                    retrieve(node);
                    break;
                case '2':
                    find(node);
                    break;
                case '3':
                    showChildren(node);
                    break;
                case '4':
                    showDescendants(node);
                    break;
                default:
                    cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
                    break;
                }
            }
            break;

        case '5':
        cout << "\n˚₊‧꒰ NODE TRANVERSAL ꒱ ‧₊˚" << endl;
            cout << "↳ PREORDER : " << endl;
            preOrder(root);
            cout << endl;
            cout << "↳ INORDER : " << endl;
            inOrder(root);
            cout << endl;
            cout << "↳ POSTORDER : " << endl;
            postOrder(root);
            cout << endl;
            break;

        case '6':
        cout << "\n˚₊‧꒰ HAPUS SUBTREE ꒱ ‧₊˚" << endl;
            cout << "↳ MASUKAN NODE SUBTREE YANG INGIN DIHAPUS : ";
            cin >> data;
            node = findNode(root, data);
            deleteSub(node);
            break;
        case '7':
            clear();
            break;
        case '8':
        cout << "\n˚₊‧꒰ KARAKTERISTIK ꒱ ‧₊˚" << endl;
            characteristic();
            break;
        case '0':
            break;
        default:
            cout << "⊹ • PILIHAN TIDAK VALID • ⊹" << endl;
            break;
        }
    } while (choice != '0');
}

// MAIN PROGRAM
int main()
{
    init_182_ara();
    menu();
    return 0;
}
