/**
 * @param {number} init
 * @return {Object}
 */
var createCounter = function(init) {
    let current = init;  // stored in closure
    
    return {
        increment: function() {
            current++;
            return current;
        },
        decrement: function() {
            current--;
            return current;
        },
        reset: function() {
            current = init;
            return current;
        }
    };
};