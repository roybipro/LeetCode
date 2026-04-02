/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        return obj
            .filter(Boolean) // remove falsy values
            .map(compactObject); // recursively process elements
    } 
    else if (obj !== null && typeof obj === "object") {
        let result = {};
        for (let key in obj) {
            let value = compactObject(obj[key]);
            if (Boolean(value)) {
                result[key] = value;
            }
        }
        return result;
    }
    return obj;
};