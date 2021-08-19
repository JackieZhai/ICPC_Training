///二叉树相关

///知道先序、中序，求后序
 struct TreeNode
 {
    struct TreeNode* left;
    struct TreeNode* right;
    char  elem;
 };
 void BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
 {
   if(length == 0)
     {
       //cout<<"invalid length";
       return;
     }
   TreeNode* node = new TreeNode;//Noice that [new] should be written out.
   node->elem = *preorder;
   int rootIndex = 0;
   for(;rootIndex < length; rootIndex++)
     {
       if(inorder[rootIndex] == *preorder)
       break;
     }
   //Left
   BinaryTreeFromOrderings(inorder, preorder +1, rootIndex);
   //Right
   BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
   cout<<node->elem<<endl;
   return;
 }
 int main(int argc, char* argv[])
 {
     printf("Hello World!\n");
     char* pr="GDAFEMHZ";
     char* in="ADEFGHMZ";
     BinaryTreeFromOrderings(in, pr, 8);
     printf("\n");
     return 0;
 }


///知道中序、后序，求先序
struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char  elem;
};
TreeNode* BinaryTreeFromOrderings(char* inorder, char* aftorder, int length)
{
    if(length == 0)
    {
        return NULL;
    }
    TreeNode* node = new TreeNode;//Noice that [new] should be written out.
    node->elem = *(aftorder+length-1);
    std::cout<<node->elem<<std::endl;
    int rootIndex = 0;
    for(;rootIndex < length; rootIndex++)//a variation of the loop
    {
        if(inorder[rootIndex] ==  *(aftorder+length-1))
            break;
    }
    node->left = BinaryTreeFromOrderings(inorder, aftorder , rootIndex);
    node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, aftorder + rootIndex , length - (rootIndex + 1));

    return node;
}
int main(int argc, char** argv)
{
    char* af="AEFDHZMG";
    char* in="ADEFGHMZ";
    BinaryTreeFromOrderings(in, af, 8);
    printf("\n");
    return 0;
}


///层序遍历
/*二叉树结构体，并且构建了有参构造函数*/
struct BinaryTree
{
    int vec;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree(int data)
        :vec(data), left(nullptr), right(nullptr){}
};
/*队列实现层序遍历*/
void printTree(BinaryTree* arr[])
{
    queue<BinaryTree*> rel; //定义一个队列，数据类型是二叉树指针，不要仅是int！！不然无法遍历
    rel.push(arr[0]);
    while (!rel.empty())
    {
        BinaryTree* front = rel.front();
        printf("%d\n", front->vec);
        rel.pop();                  //删除最前面的节点
        if (front->left != nullptr) //判断最前面的左节点是否为空，不是则放入队列
            rel.push(front->left);
        if (front->right != nullptr)//判断最前面的右节点是否为空，不是则放入队列
            rel.push(front->right);
    }
}
int main()
{
    /*构建二叉树*/
    BinaryTree* s_arr[6];
    s_arr[0] = new BinaryTree(0);
    s_arr[1] = new BinaryTree(1);
    s_arr[2] = new BinaryTree(2);
    s_arr[3] = new BinaryTree(3);
    s_arr[4] = new BinaryTree(4);
    s_arr[5] = new BinaryTree(5);
    s_arr[0]->left = s_arr[1];  //   0
    s_arr[0]->right = s_arr[2]; //  1  2
    s_arr[1]->left = s_arr[3];  // 3     5
    s_arr[3]->left = s_arr[4];  //4
    s_arr[2]->right = s_arr[5]; //所以层序遍历的结果为：0 1 2 3 5 4
    /*层次遍历打印所有节点*/
    printTree(s_arr);
    /*释放所有空间*/
    for (int i = 0; i < 6; i++)
        delete s_arr[i];
    return 0;
}


///镜面反转
void MirrorRecursively(TreeNode *pRoot)
{
    if((pRoot == NULL) || (pRoot->left == NULL && pRoot->right))
        return;

    TreeNode *pTemp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = pTemp;

    if(pRoot->left)
        MirrorRecursively(pRoot->left);

    if(pRoot->right)
        MirrorRecursively(pRoot->right);
}
