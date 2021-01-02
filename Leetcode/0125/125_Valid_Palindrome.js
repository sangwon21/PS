var isAlpha = function(ch){
    return typeof ch === "string" && ch.length === 1
           && (ch >= "a" && ch <= "z" || ch >= "A" && ch <= "Z" || ch >= '0' && ch <= '9');
  }
  
  /**
   * @param {string} s
   * @return {boolean}
   */
  var isPalindrome = function(s) {
      if(!s) {
          return true;
      }
      
      const stack = [];
      
      for (let i = 0; i < s.length; i++) {
          if (!isAlpha(s[i])) {
              continue;
          }
          const target = s[i].toLowerCase();
          stack.push(target);
      }
      
      for (let i = 0; i < parseInt(stack.length); i++) {
          if (stack[i] !== stack[stack.length - 1 - i]) {
              return false;
          }
      }
      
      return true;
  };