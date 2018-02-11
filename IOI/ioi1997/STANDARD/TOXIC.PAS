{$M 65520,0,655360}
program Toxic;
  {HGF 1998-3-24}
  const
    NameIn ='TOXIC.DAT';                                    {�����ļ�}
    NameOut='TOXIC.OUT';                                    {����ļ�}
    Move:array[1..6,1..3]of ShortInt=                    {6���ƶ�����}
         ((0,0,1),(0,0,-1),
          (0,1,0),(0,-1,0),
          (1,0,0),(-1,0,0));
    Max=32;                                                 {�������}
  type
    aType=array[0..Max+1,0..Max+1]of Byte;
    bType=array[0..Max+1]of aType;
  var
    Ans:Integer;                                            {���մ�}
    Block:bType;                                        {������ս��}
      {��ʾ�����������и�������������;1��ʾ·��;0��ʾδ��;2��ʾ�ѳ�}
    x,y,Bl,w:array[0..3]of Integer;
  procedure DataIn;                                     {�����������}
    var
      f:Text;
      i,j:Integer;
    begin
      Assign(f,NameIn);
      Reset(f);
      ReadLn(f,x[1],x[2],x[3]);                           {���볤����}
      y[1]:=1; y[2]:=2; y[3]:=3;                    {���³����ߵ�˳��}
      for i:=1 to 2 do                     {�ѳ���������,ͬʱ����˳��}
        for j:=i+1 to 3 do
          if x[j]<x[i] then
            begin
              x[0]:=x[j]; x[j]:=x[i]; x[i]:=x[0];
              y[0]:=y[j]; y[j]:=y[i]; y[i]:=y[0]
            end;
      Close(f)
    end; {of DataIn}
  procedure GetAns(m,n,l,z1,z2,z3:Integer);
                               {���㳤���߷ֱ�Ϊn,l,m��������Ľ��ƽ�}
    var
      a:array[1..2]of aType;                      {���С��Ļ���·��}
      b:bType;                                          {��ųԵĽ��}
      Now:Integer;                                {���Ե�������ĸ���}
      p,i,j:Integer;
    procedure GetEasy;                            {��ȡС��Ļ���·��}
      var
        i,j:Integer;
      begin
        FillChar(a,SizeOf(a),0);
        for i:=1 to n do
          case i mod 8 of
            1:begin
                a[2][i][1]:=1;
                for j:=1 to l do
                  a[1][i][j]:=1
              end;
            2:begin
                a[1][i][l]:=1;
                a[2][i][l]:=1
              end;
            3:begin
                a[1][i][1]:=1;
                for j:=1 to l do
                  a[2][i][j]:=1
              end;
            4:for j:=1 to l do
                a[1][i][j]:=1;
            5:begin
                a[1][i][l]:=1;
                for j:=1 to l do
                  a[2][i][j]:=1
              end;
            6:begin
                a[1][i][1]:=1;
                a[2][i][1]:=1
              end;
            7:begin
                a[2][i][l]:=1;
                for j:=1 to l do
                  a[1][i][j]:=1
              end;
            0:for j:=1 to l do
                a[2][i][j]:=1
          end
      end; {of GetEasy}
    procedure Change;                           {�Ի�����·�����е���}
      begin
        case n mod 8 of
          1:if n>1 then
              begin
                a[2][n-1][l]:=0;
                a[2][n-2][l]:=0;
                a[1][n-2][l]:=0;
                a[2][n-1][l-1]:=1;
                a[2][n-2][l-1]:=1
              end;
          4:begin
              a[2][n-1][l]:=0;
              a[2][n-2][l-1]:=1
            end;
          5:begin
              a[1][n-1][1]:=0;
              a[1][n-2][1]:=0;
              a[2][n-2][1]:=0;
              a[1][n-1][2]:=1;
              a[1][n-2][2]:=1
            end;
          0:begin
              a[1][n-1][1]:=0;
              a[1][n-2][2]:=1
            end
        end;
        if n mod 8 in [3,6] then a[1][n][1]:=0;
        a[2,1,1]:=0;
        if n mod 8 in [2,7] then a[2][n][l]:=0
      end; {of Change}
    procedure FillSelf;                     {Ѱ����;�����ɳԵķ���}
      var
        i,j,k,o,xx,yy,zz:Integer;
        Ok:Byte;
      begin
        for i:=1 to m do
          for j:=1 to n do
            for k:=1 to l do
              if b[i][j][k]=0 then
                begin
                  Ok:=0;
                  for o:=1 to 6 do
                    begin
                      xx:=i+Move[o,1];
                      yy:=j+Move[o,2];
                      zz:=k+Move[o,3];
                      case b[xx][yy][zz] of
                        1:begin
                            Inc(Ok);
                            if Ok>1 then Break
                          end;
                        2:begin
                            Ok:=2;
                            Break
                          end
                      end
                    end;
                  if Ok=1 then b[i][j][k]:=2        {�ɳԵķ��������}
                end
      end; {of FillSelf}
    procedure Link;                   {�ϲ�������εĽ�����õ������}
      var
        i:Integer;
        Up:Boolean;
      begin
        Up:=n mod 8 in [1,2,4,7];
        for i:=1 to m do
          case i mod 3 of
            1:begin
                b[p+i]:=a[1];
                if (i mod 6=4) and not Up then
                  begin
                    b[p+i][n][1]:=1;
                    b[p+i-1][n][1]:=1
                  end
              end;
            2:begin
                b[p+i]:=a[2];
                if (i mod 6=5) then
                  begin
                    b[p+i][1][1]:=1;
                    b[p+i+1][1][1]:=1
                  end;
                if (i mod 6=2) and Up then
                  begin
                    b[p+i][n][l]:=1;
                    b[p+i+1][n][l]:=1
                  end
              end
          end
      end; {of Link}
    procedure GetBlock;                   {�����ܹ����Ե�������ĸ���}
      var
        i,j,k:Integer;
      begin
        Now:=0;
        for i:=1 to m do
          for j:=1 to n do
            for k:=1 to l do
              if b[i][j][k]<>0 then Inc(Now)
      end; {of GetBlock}
    begin {of GetAns}
      FillChar(b,SizeOf(b),0);
      if m>1                                                  {�߶�>1}
      then begin
             if m mod 3=1
             then p:=1
             else p:=0;
             GetEasy;                                   {ȡ�û���;��}
             if m>4
             then begin
                    Change;                                     {����}
                    Link                                        {�ϲ�}
                  end
             else begin
                    b[p+1]:=a[2];
                    b[p+2]:=a[1]
                  end;
             if p=1 then b[1,1,1]:=1
           end
      else begin                                            {��ά���}
             {��ȡ����;��}
             for i:=1 to n do
               case i mod 6 of
                 1,4:for j:=1 to l do b[1][i][j]:=1;
                 2,3:b[1][i][l]:=1;
                 5,0:b[1][i][1]:=1
               end;

             if n mod 3=0 then
               begin                                            {����}
                 if n>3 then
                   if n mod 6=0
                   then begin
                          b[1][n-3][l-1]:=1;
                          b[1][n-2][l]:=0;
                          b[1][n-1][l]:=1;
                          for j:=l-2 downto 1 do
                            if Odd(j)=Odd(l)
                            then b[1][n-4][j]:=2
                            else b[1][n-3][j]:=2
                        end
                   else begin
                          b[1][n-3][2]:=1;
                          b[1][n-2][1]:=0;
                          b[1][n-1][1]:=1;
                          for j:=3 to l do
                            if Odd(j)
                            then b[1][n-4][j]:=2
                            else b[1][n-3][j]:=2
                        end;
                 for j:=1 to l do b[1][n][j]:=1
               end
           end;
      FillSelf;                             {������;�����ɳԵ�������}
      GetBlock;                               {���㱻�Ե�������ĸ���}
      if Now>Ans then                                         {���Ž�}
        begin
          Ans:=Now;                                           {���½�}
          Block:=b;
          Bl[1]:=z1;
          Bl[2]:=z2;
          Bl[3]:=z3
        end
    end; {of GetAns}
  procedure Process;                                        {��������}
    {�Գ����߽�������,�����õĽ��ƽ�}
    begin
      Ans:=0;
      case x[1] of
        1:if x[2]<3                                            {��Ϊ1}
          then GetAns(1,x[2],x[3],y[1],y[2],y[3])
          else begin
                 GetAns(1,x[2],x[3],y[1],y[2],y[3]);
                 GetAns(1,x[3],x[2],y[1],y[3],y[2])
               end;
        2:begin                                                {��Ϊ2}
            GetAns(2,x[2],x[3],y[1],y[2],y[3]);
            GetAns(2,x[3],x[2],y[1],y[3],y[2])
          end
        else begin                                              {����}
               GetAns(x[1],x[2],x[3],y[1],y[2],y[3]);
               GetAns(x[1],x[3],x[2],y[1],y[3],y[2]);
               GetAns(x[2],x[1],x[3],y[2],y[1],y[3]);
               GetAns(x[2],x[3],x[1],y[2],y[3],y[1]);
               GetAns(x[3],x[1],x[2],y[3],y[1],y[2]);
               GetAns(x[3],x[2],x[1],y[3],y[2],y[1])
             end
      end
    end; {of Process}
  procedure DataOut;                                    {�����������}
    var
      g:Text;
      i:Integer;
      x,y,z,xx,yy,zz,k:Integer;
    procedure Say(Ch:Char;x,y,z:Integer);                 {������ļ�}
      var
        i:Integer;
        o:array[1..3]of Integer;
      begin
        o[1]:=x;
        o[2]:=y;
        o[3]:=z;
        Write(g,Ch);
        for i:=1 to 3 do
          Write(g,' ',o[w[i]]);
        WriteLn(g);
        Block[x][y][z]:=0
      end; {of Say}
    begin {of DataOut}
      for i:=1 to 3 do
        w[Bl[i]]:=i;
      Assign(g,NameOut);
      Rewrite(g);
      Say('E',1,1,1);
      Say('M',1,1,1);
      x:=1; y:=1; z:=1;
      repeat                          {�����������������С��Ķ���}
        for k:=1 to 6 do
          begin
            xx:=x+Move[k,1];
            yy:=y+Move[k,2];
            zz:=z+Move[k,3];
            if Block[xx][yy][zz]=2 then
              Say('E',xx,yy,zz)                              {����Eat}
          end;
        k:=0;
        repeat
          Inc(k);
          xx:=x+Move[k,1];
          yy:=y+Move[k,2];
          zz:=z+Move[k,3]
        until (k=7) or (Block[xx][yy][zz]=1);
        if k<7 then                                     {����Eat&Move}
          begin
            Say('E',xx,yy,zz);
            Say('M',xx,yy,zz);
            x:=xx;
            y:=yy;
            z:=zz
          end;
      until k=7;                                            {��·����}
      Close(g)
    end; {of DataOut}
  begin {of Main}
    DataIn;                                                 {��������}
    Process;                                                    {����}
    DataOut                                                 {������}
  end. {of Main}