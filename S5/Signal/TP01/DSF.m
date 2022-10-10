classdef DSF
   properties
      a0
      an
      bn
   end
   methods
       function obj = DSF(a0, an, bn)
         obj.a0 = a0;
         obj.an = an;
         obj.bn = bn;
      end
   end
end